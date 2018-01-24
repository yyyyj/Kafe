#include <iostream>
#include <cmath>

#include "vm.hpp"

namespace kafe
{

    VM::VM() :
        m_stack_size(0)
        , m_ip(0)
        , m_debug_mode(0)
    {}

    VM::~VM()
    {
        clear();
    }

    void VM::push(Value value)
    {
        m_stack.push_back(value);
        m_stack_size++;
    }

    Value VM::pop()
    {
        // return last element put on the stack
        return abc::pop(m_stack, --m_stack_size);
    }

    void VM::clear()
    {
        // cleaning the VM to run it again without creating a new instance
        m_stack.clear();
        m_stack_size = m_ip = 0;
        m_variables.clear();
        m_segments.clear();
    }

    inst_t VM::readByte(addr_t i)
    {
        if (i < m_bytecode.size())
            return m_bytecode[i];
        throw std::runtime_error("Index out of range, can not get next byte ! => Malformed bytecode");
    }

    uint8B_t VM::readXBytesInt(unsigned char bytesCount)
    {
        uint8B_t v = readByte(++m_ip);
        for (unsigned k=1; k < bytesCount; ++k)
            { v = (v << 8) + readByte(++m_ip); }
        return v;
    }

    int2B_t VM::read2BytesInt()
    {
        return abc::setSign((int2B_t) readXBytesInt(2), /* bytesCount */ 2);
    }

    int4B_t VM::read4BytesInt()
    {
        return abc::setSign((int4B_t) readXBytesInt(4), /* bytesCount */ 4);
    }

    int8B_t VM::read8BytesInt()
    {
        return abc::setSign((int8B_t) readXBytesInt(8), /* bytesCount */ 8);
    }

    double VM::readDouble()
    {
        uint4B_t int_part = read4BytesInt();
        int2B_t exp = abc::abs(read2BytesInt());
        exp = (exp > EXP_DOUBLE_LIMIT) ? EXP_DOUBLE_LIMIT : ((exp < -EXP_DOUBLE_LIMIT) ? -EXP_DOUBLE_LIMIT : exp);
        exp *= (exp & EXP_DOUBLE_LIMIT) ? (-1) : (+1);
        return double(int_part) * std::pow(10, exp);
    }

    std::string VM::readString()
    {
        uint2B_t strSize = read2BytesInt();
        if (strSize > 0)
        {
            std::string work = "";
            ++m_ip;
            for (uint2B_t j=m_ip; m_ip - j < strSize; ++m_ip)
                { work += readByte(m_ip); }
            --m_ip;
            return work;
        }
        else
            { throw std::logic_error("Invalid size given when trying to read a string"); }
    }

    bool VM::readBool()
    {
        return (readByte(++m_ip) > 0);
    }

    addr_t VM::getSegmentAddr(const std::string& segmentName)
    {
        if (m_segments.find(segmentName) != m_segments.end())
            { return m_segments[segmentName]; }
        else
            { throw std::runtime_error("Can not get the position of an undefined segment"); }
    }

    void VM::goToSegmentPosition(const std::string& segmentName)
    {
        m_ip = getSegmentAddr(segmentName) - 1; // -1 because we do that before an iteration end, so we will do ++m_ip just after
    }

    void VM::pushCallStack(const std::string& segmentName, addr_t lastPos)
    {
        // we need to keep track of what segment we jumped to, from which position,
        // to be able to go able to the caller position easily, and continue the execution
        addr_t cs_last_index = m_call_stack.size() - 1;

        // if the stack is empty or the last element on the stack isn't a call of the same segment we are calling
        if (m_call_stack.size() == 0 || m_call_stack[cs_last_index].segmentName != segmentName)
        {
            Call::Pair bloc = {/* cnt= */ 1, /* pos= */ lastPos};
            Call call_element;

            call_element.segmentName = segmentName;
            call_element.lastPositions.push_back(bloc);

            m_call_stack.push_back(call_element);
        }
        else
        {
            // the stack isn't empty and the last element is describing the same segment as the one which is being called
            addr_t lp_last_index = m_call_stack[cs_last_index].lastPositions.size() - 1;
            // if the last element on the stack of the call element is the same as the position
            // from where we are calling this segment, add one to its counter `cnt`
            if (m_call_stack[cs_last_index].lastPositions[lp_last_index].pos == lastPos)
                { ++m_call_stack[cs_last_index].lastPositions[lp_last_index].cnt; }
            else
            {
                Call::Pair bloc = {/* cnt= */ 1, /* pos= */ lastPos};
                m_call_stack[cs_last_index].lastPositions.push_back(bloc);
            }
        }
    }

    std::string VM::performJump()
    {
        // read segment name
        std::string seg_name = readString();
        // keep the last value of the instruction pointer, we'll need it
        addr_t last_pos = m_ip;
        // jump to the segment
        goToSegmentPosition(seg_name);
        // refresh the call stack and register we've jumped to `seg_name`, from `last_pos`
        // in order to be able to go back when the execution of the segment we'll end
        pushCallStack(seg_name, last_pos);

        return seg_name;
    }

    void VM::retFromSegment()
    {
        if (m_call_stack.size() > 0)
        {
            addr_t cs_last_index = m_call_stack.size() - 1;
            addr_t lp_last_index = m_call_stack[cs_last_index].lastPositions.size() - 1;
            addr_t lp = m_call_stack[cs_last_index].lastPositions[lp_last_index].pos;

            // going back to the position where the segment was called to continue the execution
            m_ip = lp;
            --m_call_stack[cs_last_index].lastPositions[lp_last_index].cnt;

            // just checking we keep within bounds of the bytecode
            if (m_ip >= m_bytecode.size())
                { throw std::logic_error("Jumping back from a segment to an invalid position in the bytecode"); }

            // the "pair" recording the multiples calls of the same segment from the same segment is now empty, pop it
            if (m_call_stack[cs_last_index].lastPositions[lp_last_index].cnt == 0)
                { abc::popNoReturn(m_call_stack[cs_last_index].lastPositions, -1); }
            // the "call element" recording the multiples calls of the same segment is now empty, pop it
            if (m_call_stack[cs_last_index].lastPositions.size() == 0)
                { abc::popNoReturn(m_call_stack, -1); }
        }
        else
            { throw std::logic_error("Can not return from a non-segment"); }
    }

    void VM::exec_handleDataTypesDecl(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_INT_2B:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "int 2B" << std::endl;

                Value v(ValueType::Int);
                v.set<int8B_t>(read2BytesInt());
                push(v);

                break;
            }

            case INST_INT_4B:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "int 4B" << std::endl;

                Value v(ValueType::Int);
                v.set<int8B_t>(read4BytesInt());
                push(v);

                break;
            }

            case INST_DOUBLE:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "double" << std::endl;

                Value v(ValueType::Double);
                v.set<double>(readDouble());
                push(v);

                break;
            }

            case INST_STR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG)  std::cerr << "str" << std::endl;

                Value a(ValueType::String, readString());
                push(a);

                break;
            }

            case INST_BOOL:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "bool" << std::endl;

                Value a(ValueType::Bool, readBool());
                push(a);

                break;
            }

            case INST_ADDR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "addr" << std::endl;

                Value a(ValueType::Addr, getSegmentAddr(readString()));
                push(a);

                break;
            }

            case INST_LIST:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "list" << std::endl;

                uint4B_t nb_elements = read4BytesInt();
                Value c(ValueType::List);
                while (nb_elements != 0)
                {
                    c.getRef<Value::list_t>().insert(c.getRef<Value::list_t>().begin(), pop());
                    nb_elements--;
                }

                break;
            }

            case INST_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "var" << std::endl;

                Value a(ValueType::Var, readString());
                push(a);

                break;
            }

            case INST_STRUCT:
            case INST_DECL_STRUCT:
            case INST_STRUCT_GETM:
            case INST_STRUCT_SETM:
            case INST_STRUCT_HASM:
            {
                exec_handleStructures(instruction);
                break;
            }

            case INST_DEL_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "delete variable" << std::endl;

                std::string var_name = readString();
                if (m_variables.find(var_name) != m_variables.end())
                    { m_variables.erase(m_variables.find(var_name)); }
                else
                    { throw std::logic_error("Can not delete a non-existing variable"); }

                break;
            }
        }
    }

    void VM::exec_handleStructures(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_STRUCT:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure" << std::endl;

                Value a(ValueType::Struct);
                // getting the structure name
                std::string struct_name = readString();
                // to take the default data in it and fill the new object with those
                if (m_struct_definitions.find(struct_name) != m_struct_definitions.end())
                {
                    // init the newly created structure from its "parent"
                    a.set<Structure>(m_struct_definitions[struct_name]);
                    // push the given arguments
                    uint2B_t nb_args = read2BytesInt();
                    for (uint2B_t j=0; j < nb_args; ++j)
                    {
                        Value name = pop();
                        Value val = pop();

                        // we check that the given "name" is a valid variable name
                        if (name.type == ValueType::Var)
                        {
                            // and we perform some type checking
                            StructElem* pse = a.getRef<Structure>().findMember(name.get<std::string>());
                            if (pse != nullptr)
                            {
                                if (pse->val.type == val.type)
                                    { a.getRef<Structure>().add(name.get<std::string>(), val); }
                                else
                                    { throw std::logic_error("Type error while trying to set an argument of a structure"); }
                            }
                            else
                                { throw std::runtime_error("Can not set a non-member of a structure using a structure declaration"); }
                        }
                        else
                            { throw std::logic_error("The name of the member to set in the given structure isn't a string"); }
                    }
                }
                else
                    { throw std::runtime_error("Can not use an undefined structure"); }
                push(a);

                break;
            }

            case INST_DECL_STRUCT:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "declare structure" << std::endl;

                std::string name = readString();
                uint2B_t pairs_nb = read2BytesInt();
                m_struct_definitions[name] = Structure();
                for (uint2B_t j=0; j < pairs_nb; ++j)
                {
                    Value name = pop();
                    Value val = pop();

                    if (name.type == ValueType::Var)
                        { m_struct_definitions[name.get<std::string>()].add(name.get<std::string>(), val); }
                    else
                        { throw std::logic_error("Expecting a variable when declaring a structure's member"); }
                }

                break;
            }

            case INST_STRUCT_GETM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure get member" << std::endl;

                std::string name = readString();
                if (m_variables.find(name) != m_variables.end())
                {
                    std::string member = readString();
                    StructElem* pse = m_variables[name].getRef<Structure>().findMember(member);
                    if (pse != nullptr)
                        { push(pse->val); }
                    else
                        { throw std::runtime_error("Can not get a non-existing member of a structure"); }
                }
                else
                    { throw std::logic_error("Can not get a member of a non-existing structure"); }

                break;
            }

            case INST_STRUCT_SETM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure set member" << std::endl;

                std::string name = readString();
                if (m_variables.find(name) != m_variables.end())
                {
                    std::string member = readString();
                    m_variables[name].getRef<Structure>().set(member, pop());
                }
                else
                    { throw std::logic_error("Can not set a member of a non-existing structure"); }

                break;
            }

            case INST_STRUCT_HASM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure has member" << std::endl;

                std::string name = readString();
                if (m_variables.find(name) != m_variables.end())
                {
                    std::string member = readString();
                    if (m_variables[name].getRef<Structure>().findMember(member) != nullptr)
                        { push(Value(ValueType::Bool, true)); }
                    else
                        { push(Value(ValueType::Bool, false)); }
                }
                else
                    { throw std::logic_error("Can not get a member of a non-existing structure"); }

                break;
            }
        }
    }

    void VM::exec_handleSegments(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_SEGMENT:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "segment" << std::endl;

                // we read the size of the name of the segment
                std::string seg_name = readString();
                // we get the size of the segment and jump to the end of it, we don't want to execute it, it wasn't called,
                // only defined
                uint2B_t seg_size = read2BytesInt();
                // we try to add the segment position to the "segment register" if it wasn't registered before
                if (m_segments.find(seg_name) == m_segments.end())
                    { m_segments[seg_name] = m_ip + 1; }  // +1 because we want the next byte, not the current one
                if (seg_size > 0 && m_ip + seg_size < m_bytecode.size())
                    { m_ip += seg_size; }
                else
                    { throw std::logic_error("Invalid bloc count for the segment"); }

                break;
            }

            case INST_DECL_SEG:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "declare segment" << std::endl;

                // we get the size of the name of the segment and read this name
                std::string seg_name = readString();
                // and we read its position in the m_bytecode
                m_segments[seg_name] = read2BytesInt();

                break;
            }

            case INST_STORE_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "store var" << std::endl;

                Value var_name = pop();
                Value val = pop();

                if (var_name.type == ValueType::Var)
                    { m_variables[var_name.get<std::string>()] = val; }
                else
                    { throw std::logic_error("Can not store a value into a non-variable"); }

                break;
            }

            case INST_LOAD_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "push var" << std::endl;

                // we read the size of the var name and read it
                std::string v = readString();
                // if the variable can be found, push it on the stack
                if (m_variables.find(v) != m_variables.end())
                    { push(m_variables[v]); }
                else
                    { throw std::runtime_error("Can not push an undefined variable onto the stack"); }

                break;
            }

            case INST_DUP:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "duplicate" << std::endl;

                if (m_stack.size() > 0)
                {
                    Value a = pop();
                    // push a 2 times in a row, because we pop it from the stack and want to duplicate the value
                    // stored at stack[-1]
                    push(a); push(a);
                }
                else
                    { throw std::logic_error("Can not duplicate the last value of the stack if there isn't any"); }

                break;
            }

            case INST_JUMP:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump" << std::endl;

                std::string seg_name = performJump();
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << seg_name << std::endl;

                break;
            }

            case INST_JUMP_IF:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump if" << std::endl;

                // get a value on the stack and try to compare it with true
                Value a = pop();
                if (a == Value(ValueType::Bool, true))
                {
                    std::string seg_name = performJump();
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << seg_name << std::endl;
                }

                break;
            }

            case INST_JUMP_IFN:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump if not" << std::endl;

                Value a = pop();
                if (a == Value(ValueType::Bool, false))
                {
                    std::string seg_name = performJump();
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << seg_name << std::endl;
                }
                break;
            }

            case INST_RET:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "ret" << std::endl;

                retFromSegment();
                break;
            }
        }
    }

    void VM::exec_handleBuiltins()
    {
        uint2B_t instruction = read2BytesInt();

        switch (instruction)
        {
            case INST_ADD:
            {
                std::cerr << "add" << std::endl;

                Value b = pop();
                Value a = pop();

                if (a.type == b.type)
                {
                    if (a.type == ValueType::Int)
                    {
                        Value c(ValueType::Int, a.get<int8B_t>() + b.get<int8B_t>());
                        push(c);
                    }
                    else if (a.type == ValueType::Double)
                    {
                        Value c(ValueType::Double, a.get<double>() + b.get<double>());
                        push(c);
                    }
                    else if (a.type == ValueType::String)
                    {
                        Value c(ValueType::String, a.get<std::string>() + b.get<std::string>());
                        push(c);
                    }
                    else
                        { throw std::logic_error("Can not add two " + convertTypeToString(a.type)); }
                }
                else
                    { throw std::logic_error("Can not add two variables of heterogeneous types"); }

                break;
            }

            case INST_NE:
            {
                std::cerr << "ne" << std::endl;

                Value b = pop();
                Value a = pop();

                if (a.type != b.type)
                {
                    Value c(ValueType::Bool, true);
                    push(c);
                }
                else
                {
                    Value c(ValueType::Bool, (a != b));
                    push(c);
                }

                break;
            }

            default:
            {
                throw std::runtime_error("Invalid byte used to identify a non-existing procedure : " +
                                         abc::str((unsigned) instruction));
            }
        }
    }

    bytecode_t VM::readFile(const std::string& filePath)
    {
        // open the file and get its size
        std::ifstream ifs(filePath, std::ios::binary | std::ios::ate);
        if (!ifs.good())
            { throw std::runtime_error("Can not open the given file"); }
        std::ifstream::pos_type pos = ifs.tellg();
        // reserve the appropriate size
        std::vector<char> temp(pos);
        // seek to the beginning of the file and read
        ifs.seekg(0, std::ios::beg);
        ifs.read(&temp[0], pos);
        ifs.close();

        bytecode_t bytes(pos);
        for (std::size_t i=0; i < pos; ++i)
            { bytes[i] = (inst_t) temp[i]; }

        return bytes;
    }

    int VM::execFromFile(const std::string& filePath)
    {
        load(readFile(filePath));
        return exec();
    }

    void VM::setMode(int mode)
    {
        m_debug_mode |= mode;
    }

    void VM::load(bytecode_t bytecode)
    {
        clear();
        m_bytecode = bytecode;
    }

    int VM::exec()
    {
        if (m_bytecode.size() != 0)
        {
            clear();

            for (m_ip=0; m_ip < m_bytecode.size(); ++m_ip)
            {
                inst_t instruction = readByte(m_ip);
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "[" << m_ip << "] " << (unsigned) instruction << " ";

                if (INST_INT_2B <= instruction && instruction <= INST_DEL_VAR)
                    { exec_handleDataTypesDecl(instruction); }
                else if (INST_SEGMENT <= instruction && instruction <= INST_RET)
                    { exec_handleSegments(instruction); }
                else if (instruction == INST_PROCEDURE)
                    { exec_handleBuiltins(); }
                else
                {
                    if (instruction != 0x00)
                        { throw std::runtime_error("Can not identify the instruction " + abc::str((unsigned) instruction)); }
                }
            }

            return 0;
        }
        else
            { throw std::logic_error("Can not run if no bytecode were given"); }
    }

    int VM::callSegment(const std::string& seg_name)
    {
        // set the `last_pos` as the \0 byte to stop the execution of the segment right after we return from it
        addr_t last_pos = m_bytecode.size() - 1;
        // jump to the segment
        goToSegmentPosition(seg_name);
        // refresh the call stack and register we've jumped to `seg_name`, from `last_pos`
        // in order to be able to go back when the execution of the segment we'll end
        pushCallStack(seg_name, last_pos);

        return exec();
    }

    ValueStack_t& VM::getStack()
    {
        return m_stack;
    }

    void VM::saveBytecode(const std::string& filename)
    {
        std::ofstream output(filename, std::ios::binary);
        output.write((char*)&m_bytecode[0], m_bytecode.size());
        output.close();
    }

}  // namespace kafe

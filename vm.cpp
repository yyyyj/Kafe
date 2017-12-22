#include <iostream>
#include <string.h>

#include "vm.hpp"

namespace kafe
{

    VM::VM() :
        m_stack_size(0)
        , m_ip(0)
        , m_debug(false)
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
        m_stack_size = 0;
        m_ip = 0;
        m_variables.clear();
        m_segments.clear();
    }

    inst_t VM::getByte(bytecode_t& bytecode, std::size_t i)
    {
        if (i < bytecode.size())
            return bytecode[i];
        throw std::runtime_error("Index out of range, can not get next byte ! => Malformed bytecode");
    }

    long VM::getXBytesInt(bytecode_t& bytecode, unsigned bytesCount)
    {
        long v = getByte(bytecode, ++m_ip);
        for (unsigned k=1; k < bytesCount; ++k)
            { v = (v << 8) + getByte(bytecode, ++m_ip); }
        return v;
    }

    int VM::get2BytesInt(bytecode_t& bytecode)
    {
        return getXBytesInt(bytecode, 2);
    }

    long VM::get4BytesInt(bytecode_t& bytecode)
    {
        return getXBytesInt(bytecode, 4);
    }

    std::string VM::readString(bytecode_t& bytecode, std::size_t strSize)
    {
        std::string work = "";
        ++m_ip;
        for (std::size_t j=m_ip; m_ip - j < strSize; ++m_ip)
            { work += getByte(bytecode, m_ip); }
        --m_ip;
        return work;
    }

    bool VM::readBool(bytecode_t& bytecode)
    {
        return (getByte(bytecode, ++m_ip) > 0);
    }

    std::size_t VM::getSegmentAddr(const std::string& segmentName)
    {
        if (m_segments.find(segmentName) != m_segments.end())
            { return m_segments[segmentName]; }
        else
            { throw std::runtime_error("Can not get the position of an undefined segment"); }
    }

    std::string VM::getSegmentName(bytecode_t& bytecode)
    {
        std::size_t str_size = get2BytesInt(bytecode);
        if (str_size > 0)
            { return readString(bytecode, str_size); }
        else
            { throw std::logic_error("Invalid size given for the segment name to fetch"); }
    }

    void VM::goToSegmentPosition(const std::string& segmentName)
    {
        m_ip = getSegmentAddr(segmentName) - 1; // -1 because we do that before an iteration end, so we will do ++m_ip just after
    }

    void VM::pushCallStack(const std::string& segmentName, std::size_t lastPos)
    {
        // we need to keep track of what segment we jumped to, from which position,
        // to be able to go able to the caller position easily, and continue the execution
        std::size_t cs_last_index = m_call_stack.size() - 1;

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

            std::size_t lp_last_index = m_call_stack[cs_last_index].lastPositions.size() - 1;
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

    std::string VM::performJump(bytecode_t& bytecode)
    {
        // read segment name
        std::string seg_name = getSegmentName(bytecode);
        // keep the last value of the instruction pointer, we'll need it
        std::size_t last_pos = m_ip;
        // jump to the segment
        goToSegmentPosition(seg_name);
        // refresh the call stack and register we've jumped to `seg_name`, from `last_pos`
        // in order to be able to go back when the execution of the segment we'll end
        pushCallStack(seg_name, last_pos);

        return seg_name;
    }

    void VM::retFromSegment(bytecode_t& bytecode)
    {
        if (m_call_stack.size() > 0)
        {
            std::size_t cs_last_index = m_call_stack.size() - 1;
            std::size_t lp_last_index = m_call_stack[cs_last_index].lastPositions.size() - 1;
            std::size_t lp = m_call_stack[cs_last_index].lastPositions[lp_last_index].pos;

            // going back to the position where the segment was called to continue the execution
            m_ip = lp;
            --m_call_stack[cs_last_index].lastPositions[lp_last_index].cnt;

            // just checking we keep within bounds of the bytecode
            if (m_ip >= bytecode.size())
                { throw std::logic_error("Jumping back from a segment to an invalid position in the bytecode"); }

            // the "pair" recording the multiples calls of the same segment from the same segment is now empty, pop it
            if (m_call_stack[cs_last_index].lastPositions[lp_last_index].cnt == 0)
                { abc::pop_no_return(m_call_stack[cs_last_index].lastPositions, -1); }
            // the "call element" recording the multiples calls of the same segment is now empty, pop it
            if (m_call_stack[cs_last_index].lastPositions.size() == 0)
                { abc::pop_no_return(m_call_stack, -1); }
        }
        else
            { throw std::logic_error("Can not return from a non-segment"); }
    }

    bool VM::canValueCompareTo(Value val, bool c)
    {
        // TODO : implement comparison operator in the struct kafe::Value

        // utility to compare a value to a boolean
        if (val.type == TYPE_STRUCT)
            { return true; }  // convention
        else if (val.type == TYPE_VAR || val.type == TYPE_STRUCT_DECL)
            { throw std::logic_error("Malformed bytecode, trying to compare a boolean with an unfinished bytecode instruction"); }

        return (val.type == TYPE_BOOL && val.boolValue == c) ||
               (val.type == TYPE_INT && bool(val.intValue) == c) ||
               (val.type == TYPE_DOUBLE && bool(val.doubleValue) == c) ||
               (val.type == TYPE_LIST && bool(val.listValue.size()) == c) ||
               (val.type == TYPE_STRING && bool(val.stringValue.size()) == c);
    }

    void VM::builtins(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_ADD:
            {
                std::cout << "add" << std::endl;

                Value b = pop();
                Value a = pop();

                if (a.type == b.type)
                {
                    if (a.type == TYPE_INT)
                    {
                        Value c;
                        c.type = TYPE_INT;
                        c.intValue = b.intValue + a.intValue;
                        push(c);
                    }
                    else if (a.type == TYPE_STRING)
                    {
                        Value c;
                        c.type = TYPE_STRING;
                        c.stringValue = std::string(a.stringValue) + std::string(b.stringValue);
                        push(c);
                    }
                    else
                        { throw std::logic_error("Can not add two booleans"); }
                }
                else
                    { throw std::logic_error("Can not add two variables of heterogeneous types"); }

                break;
            }

            case INST_NE:
            {
                std::cout << "ne" << std::endl;

                Value b = pop();
                Value a = pop();

                if (a.type != b.type)
                {
                    Value c;
                    c.type = TYPE_BOOL;
                    c.boolValue = true;
                    push(c);
                }
                else
                {
                    if ((a.type == TYPE_BOOL && a.boolValue != b.boolValue) ||
                        (a.type == TYPE_INT && a.intValue != b.intValue) ||
                        (a.type == TYPE_STRING && a.stringValue != b.stringValue))
                    {
                        Value c;
                        c.type = TYPE_BOOL;
                        c.boolValue = true;
                        push(c);
                    }
                    else
                    {
                        Value c;
                        c.type = TYPE_BOOL;
                        c.boolValue = false;
                        push(c);
                    }
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
        std::ifstream::pos_type pos = ifs.tellg();
        // reserve the appropriate size
        std::vector<char> temp(pos);
        // seek to the beginning of the file and read
        ifs.seekg(0, std::ios::beg);
        ifs.read(&temp[0], pos);

        bytecode_t bytes(pos);
        for (std::size_t i=0; i < pos; ++i)
            { bytes[i] = (inst_t) temp[i]; }

        return bytes;
    }

    int VM::execFromFile(const std::string& filePath)
    {
        bytecode_t bytecode = readFile(filePath);
        return exec(bytecode);
    }

    int VM::exec(bytecode_t bytecode)
    {
        clear();

        for (m_ip=0; m_ip < bytecode.size(); ++m_ip)
        {
            inst_t instruction = getByte(bytecode, m_ip);
            if (m_debug) std::cout << "[" << m_ip << "] " << (int)instruction << " ";

            switch (instruction)
            {
                case INST_INT_2B:
                {
                    if (m_debug) std::cout << "int 2B" << std::endl;

                    Value v;
                    v.type = TYPE_INT;
                    v.intValue = get2BytesInt(bytecode);
                    push(v);

                    break;
                }

                case INST_INT_4B:
                {
                    if (m_debug) std::cout << "int 4B" << std::endl;

                    Value v;
                    v.type = TYPE_INT;
                    v.intValue = get4BytesInt(bytecode);
                    push(v);

                    break;
                }

                case INST_DOUBLE:
                {
                    if (m_debug) std::cout << "double" << std::endl;

                    break;
                }

                case INST_STR:
                {
                    if (m_debug)  std::cout << "str" << std::endl;

                    std::size_t str_size = get2BytesInt(bytecode);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_STRING;
                        a.stringValue = readString(bytecode, str_size);
                        push(a);
                    }
                    else
                        { throw std::logic_error("Invalid size given for the string to store"); }

                    break;
                }

                case INST_BOOL:
                {
                    if (m_debug) std::cout << "bool" << std::endl;

                    Value a;
                    a.type = TYPE_BOOL;
                    a.boolValue = readBool(bytecode);
                    push(a);

                    break;
                }

                case INST_ADDR:
                {
                    if (m_debug) std::cout << "addr" << std::endl;

                    break;
                }

                case INST_LIST:
                {
                    if (m_debug) std::cout << "list" << std::endl;

                    std::size_t nb_elements = getXBytesInt(bytecode);
                    Value c;
                    c.type = TYPE_LIST;
                    while (nb_elements != 0)
                    {
                        c.listValue.insert(c.listValue.begin(), pop());
                        nb_elements--;
                    }

                    break;
                }

                case INST_VAR:
                {
                    if (m_debug) std::cout << "var" << std::endl;

                    std::size_t str_size = get2BytesInt(bytecode);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_VAR;
                        a.stringValue = readString(bytecode, str_size);
                        push(a);
                    }
                    else
                        { throw std::logic_error("Invalid size given for the variable name to store"); }

                    break;
                }

                case INST_STRUCT:
                {
                    if (m_debug) std::cout << "structure" << std::endl;

                    std::size_t str_size = get2BytesInt(bytecode);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_STRUCT;
                        // getting the structure name
                        std::string name = readString(bytecode, str_size);
                        /**
                        // to take the default data in it and fill the new object with those
                        if (m_struct_definitions.find(name) != m_struct_definitions.end())
                        {
                            for (std::size_t j=0; j < m_struct_definitions[name].size(); ++j)
                                { a.structValue[m_struct_definitions[name][j].name] = m_struct_definitions[name][j].val; }
                            /// TODO: read arguments given if there are any
                            std::size_t arg_nb = getByte(bytecode, ++i);
                            ///for (std::size_t j=0; j < arg_nb; ++j)
                            ///    {  }
                        }
                        else
                            { throw std::runtime_error("Can not use an undefined structure"); }
                        push(a);
                        */
                    }
                    else
                        { throw std::logic_error("Invalid size given for the structure name to store"); }

                    break;
                }

                case INST_DECL_STRUCT:
                {
                    if (m_debug) std::cout << "declare structure" << std::endl;

                    /**std::size_t str_size = getByte(bytecode, ++i);
                    if (str_size > 0)
                    {
                        std::string name = readString(bytecode, i, str_size);
                        std::size_t data_quantity = getXBytesInt(bytecode, i);
                        m_struct_definitions[data_quantity] = Structure();
                        ++i;
                        for (std::size_t j=0; j < data_quantity; ++j)
                        {
                            std::size_t str_size = getByte(bytecode, i);
                            std::string name = readString(bytecode, i, str_size);
                            Value val;
                            StructElem se;
                            se.name = name;
                            se.val = val;
                            m_struct_definitions[data_quantity] = se;
                        }
                        --i;
                    }
                    else
                        { throw std::logic_error("Invalid size given for the structure name to store"); }
                    **/
                    break;
                }

                case INST_SEGMENT:
                {
                    if (m_debug) std::cout << "segment" << std::endl;

                    // we read the size of the name of the segment
                    std::size_t str_size = get2BytesInt(bytecode);
                    std::string seg_name;
                    if (str_size > 0)
                        { seg_name = readString(bytecode, str_size); }
                    else
                        { throw std::logic_error("Invalid size for the segment name"); }

                    // we try to add the segment position to the "segment register" if it wasn't registered before
                    // (using a INST_DECL_SEG for example)
                    if (m_segments.find(seg_name) == m_segments.end())
                        { m_segments[seg_name] = m_ip; }

                    // we get the size of the segment and jump to the end of it, we don't want to execute it, it wasn't called,
                    // only defined
                    std::size_t seg_size = get2BytesInt(bytecode);
                    if (seg_size > 0 && m_ip + seg_size < bytecode.size())
                        { m_ip += seg_size; }
                    else
                        { throw std::logic_error("Invalid bloc count for the segment"); }

                    break;
                }

                case INST_DECL_SEG:
                {
                    if (m_debug) std::cout << "declare segment" << std::endl;

                    // we get the size of the name of the segment and read this name
                    std::size_t str_size = get2BytesInt(bytecode);
                    std::string seg_name;
                    if (str_size > 0)
                        { seg_name = readString(bytecode, str_size); }
                    else
                        { throw std::logic_error("Invalid size for the segment name"); }

                    // and we read its position in the bytecode
                    m_segments[seg_name] = get2BytesInt(bytecode);

                    break;
                }

                case INST_STORE_VAR:
                {
                    if (m_debug) std::cout << "store var" << std::endl;

                    Value var_name = pop();
                    Value val = pop();

                    if (var_name.type == TYPE_VAR)
                        { m_variables[var_name.stringValue] = val; }
                    else
                        { throw std::logic_error("Can not store a value into a non-variable"); }

                    break;
                }

                case INST_LOAD_VAR:
                {
                    if (m_debug) std::cout << "push var" << std::endl;

                    // we read the size of the var name and read it
                    std::size_t str_size = get2BytesInt(bytecode);
                    if (str_size > 0)
                    {
                        std::string v = readString(bytecode, str_size);
                        // if the variable can be found, push it on the stack
                        if (m_variables.find(v) != m_variables.end())
                            { push(m_variables[v]); }
                        else
                            { throw std::runtime_error("Can not push an undefined variable onto the stack"); }
                    }
                    else
                        { throw std::logic_error("Invalid size given for the variable name to fetch"); }

                    break;
                }

                case INST_DUP:
                {
                    if (m_debug) std::cout << "duplicate" << std::endl;

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
                    if (m_debug) std::cout << "jump" << std::endl;

                    std::string seg_name = performJump(bytecode);
                    if (m_debug) std::cout << "    jumping to : " << seg_name << std::endl;

                    break;
                }

                case INST_JUMP_IF:
                {
                    if (m_debug) std::cout << "jump if" << std::endl;

                    // get a value on the stack and try to compare it with true
                    Value a = pop();
                    if (canValueCompareTo(a, true))
                    {
                        std::string seg_name = performJump(bytecode);
                        if (m_debug) std::cout << "    jumping to : " << seg_name << std::endl;
                    }

                    break;
                }

                case INST_JUMP_IFN:
                {
                    if (m_debug) std::cout << "jump if not" << std::endl;

                    Value a = pop();
                    if (canValueCompareTo(a, false))
                    {
                        std::string seg_name = performJump(bytecode);
                        if (m_debug) std::cout << "    jumping to : " << seg_name << std::endl;
                    }

                    break;
                }

                case INST_RET:
                {
                    if (m_debug) std::cout << "ret" << std::endl;

                    retFromSegment(bytecode);

                    break;
                }

                case INST_PROCEDURE:
                {
                    // we implement the procedure in another function, using a special code
                    // in order to be able to have (1st) more procedures and (2nd) a cleaner code
                    builtins(getByte(bytecode, ++m_ip));
                    break;
                }

                default:
                {
                    // 0x00 can be here to end the bytecode
                    if (instruction != 0x00)
                        { throw std::runtime_error("Can not identify the instruction " + abc::str((unsigned) instruction)); }
                }
            }
        }

        return 0;
    }

    void VM::setDebug(bool debug)
    {
        m_debug = debug;
    }

    ValueStack_t& VM::getStack()
    {
        return m_stack;
    }

}  // namespace kafe

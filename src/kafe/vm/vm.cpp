#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#include "vm.hpp"

namespace kafe
{

    VM::VM() : m_stack_size(0), m_ip(0), m_debug_mode(0), m_interactive_advance(0) {}

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
        return abc::pop(m_stack, m_stack_size - 1);
    }

    void VM::clear()
    {
        // cleaning the VM to run it again without creating a new instance
        m_stack.clear();
        m_stack_size = m_ip = m_interactive_advance = 0;
        m_variables.clear();
    }

    bool VM::findVar(const std::string& varName)
    {
        return m_variables.find(varName) != m_variables.end();
    }

    Value VM::getVar(const std::string& varName)
    {
        return m_variables[varName];
    }

    Value& VM::getRefVar(const std::string& varName)
    {
        return m_variables[varName];
    }

    void VM::setVar(const std::string& varName, Value v)
    {
        m_variables[varName] = v;
    }

    void VM::delVar(const std::string& varName)
    {
        m_variables.erase(m_variables.find(varName));
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
        for (unsigned char k=1; k < bytesCount; ++k)
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
        exp *= (exp & EXP_DOUBLE_SIGN) ? (-1) : (+1);
        return double(int_part) * std::pow(10, exp);
    }

    std::string VM::readString()
    {
        std::string work = "";
        ++m_ip;
        while (true)
        {
            inst_t byte = readByte(m_ip++);
            if (byte != 0x0)
                { work += byte; }
            else
                { break; }
        }
        --m_ip;
        return work;
    }

    bool VM::readBool()
    {
        return readByte(++m_ip) > 0;
    }

    void VM::performJump(bool registerCall)
    {
        addr_t last_pos;
        // keep the last value of the instruction pointer, we'll need it
        last_pos = m_ip;
        // jump to the segment
        Value p = pop();
        if (p.type != ValueType::Addr)
            { throw std::logic_error("Can not jump to something which isn't an address"); }
        // -1 because we're doing this right before the end of a loop, so we'll do a ++m_ip after
        m_ip = p.get<addr_t>() - 1;

        if (registerCall)
        {
            // refresh the call stack and register we've jumped from `last_pos`
            // in order to be able to go back when the execution of the segment we'll end
            Call c = {/* lastPos= */ last_pos, /* lastStackSize= */ m_stack.size()};
            m_call_stack.push_back(c);
        }
    }

    void VM::retFromSegment()
    {
        if (m_call_stack.size() > 0)
        {
            Call lc = abc::pop(m_call_stack, -1);
            m_ip = lc.lastPos;

            // cleaning the stack
            if (lc.lastStackSize > m_stack.size())
            {
                // we can only keep one element on the stack (the return value of the function)
                //while (lc.lastStackSize - m_stack.size() > 1)
                //    { pop(); }
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "[WARNING] entering the garbage collector (not implemented ATM), with lc.lastStackSize=" << lc.lastStackSize << " and m_stack.size()=" << m_stack.size() << std::endl;
            }
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

                Value a(ValueType::Addr);
                a.set<addr_t>(read4BytesInt());
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

                std::string name = readString();
                if (findVar(name))
                    { delVar(name); }
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
                if (findVar(name))
                {
                    std::string member = readString();
                    StructElem* pse = getRefVar(name).getRef<Structure>().findMember(member);
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
                if (findVar(name))
                {
                    std::string member = readString();
                    getRefVar(name).getRef<Structure>().set(member, pop());
                }
                else
                    { throw std::logic_error("Can not set a member of a non-existing structure"); }

                break;
            }

            case INST_STRUCT_HASM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure has member" << std::endl;

                std::string name = readString();
                if (findVar(name))
                {
                    std::string member = readString();
                    if (getRefVar(name).getRef<Structure>().findMember(member) != nullptr)
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
            case INST_STORE_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "store var" << std::endl;

                Value var_name = pop();
                Value val = pop();

                if (var_name.type == ValueType::Var)
                    { setVar(var_name.get<std::string>(), val); }
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
                if (findVar(v))
                    { push(getVar(v)); }
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

            case INST_CALL:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "call" << std::endl;

                performJump();
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << 1 + ((unsigned) m_ip) << std::endl;

                break;
            }

            case INST_JUMP:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump" << std::endl;

                performJump(/* registerCall= */ false);
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << 1 + ((unsigned) m_ip) << std::endl;

                break;
            }

            case INST_JUMP_IF:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump if" << std::endl;

                // get a value on the stack and try to compare it with true
                Value a = pop();
                if (a == Value(ValueType::Bool, true))
                {
                    performJump(/* registerCall= */ false);
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << 1 + ((unsigned) m_ip) << std::endl;
                }
                else
                    { pop(); }  // remove the address from the stack

                break;
            }

            case INST_JUMP_IFN:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "jump if not" << std::endl;

                Value a = pop();
                if (a == Value(ValueType::Bool, false))
                {
                    performJump(/* registerCall= */ false);
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "    jumping to : " << 1 + ((unsigned) m_ip) << std::endl;
                }
                else
                    { pop(); }  // remove the address from the stack

                break;
            }

            case INST_RET:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "ret" << std::endl;

                retFromSegment();

                break;
            }

            case INST_GET_CWA:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "get cwa" << std::endl;

                Value a(ValueType::Addr, m_ip);
                push(a);

                break;
            }

            case INST_PERMUTATION:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "permutation" << std::endl;

                Value b = pop();
                Value a = pop();
                push(b);
                push(a);

                break;
            }

            case INST_POP:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "pop" << std::endl;

                pop();

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
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "add" << std::endl;

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

            case INST_SUB:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "sub" << std::endl;

                Value b = pop();
                Value a = pop();

                if (a.type == b.type)
                {
                    if (a.type == ValueType::Int)
                    {
                        Value c(ValueType::Int, a.get<int8B_t>() - b.get<int8B_t>());
                        push(c);
                    }
                    else if (a.type == ValueType::Double)
                    {
                        Value c(ValueType::Double, a.get<double>() - b.get<double>());
                        push(c);
                    }
                    else
                        { throw std::logic_error("Can not substract two " + convertTypeToString(a.type)); }
                }
                else
                    { throw std::logic_error("Can not substract two variables of heterogeneous types"); }

                break;
            }

            case INST_NE:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "ne" << std::endl;

                Value b = pop();
                Value a = pop();

                Value c(ValueType::Bool, (a != b));
                push(c);

                break;
            }

            default:
            {
                throw std::runtime_error("Invalid byte used to identify a non-existing procedure : " +
                                         abc::str((unsigned) instruction));
            }
        }
    }

    void VM::interactiveMode(inst_t instruction, bool displayOnly)
    {
        // display stack + variables
        std::cerr << std::endl << "IP = " << std::setw(4) << m_ip << " | Bytecode size = " << std::setw(5) << m_bytecode.size() << " | "
                  << "Instruction = " << abc::hexstr((unsigned) instruction)    << std::endl
                  << "Stack                     | Variables                   " << std::endl
                  << "--------------------------|-----------------------------" << std::endl;
        VarStack_t::iterator it = m_variables.begin();
        for (std::size_t i=0; i < std::max(m_stack.size(), m_variables.size()); ++i)
        {
            if (i < m_stack.size())
                { std::cerr << std::setw(6) << convertTypeToString(m_stack[i].type) << " " << std::setw(18) << m_stack[i]; }
            else
                { std::cerr << "                         "; }
            std::cerr << " | ";
            if (i < m_variables.size())
            {
                std::ostringstream out;
                out << std::setw(12) << it->first << " = " << std::setw(6) << convertTypeToString(it->second.type) << " " << it->second;
                std::cerr << out.str();
                std::advance(it, 1);
            }
            std::cerr << std::endl << std::flush;
        }

        if (!displayOnly)
        {
            std::string command = "";
            while (command == "")
            {
                std::cerr << std::endl << "> ";
                std::getline(std::cin, command);

                if (command == "help")
                {
                    std::cerr << "Type `continue` to advance to the next relevant bytecode" << std::endl
                              << "     `break` to quit the interactive mode and continue the execution" << std::endl
                              << "     `advance x`, x a number between 0 and the bytecode size to read x byte without prompting again" << std::endl
                              << "     `clear` to clear the screen" << std::endl
                        ;
                    command = "";
                }
                else if (command == "continue")
                    { break; }
                else if (command == "break")
                {
                    m_debug_mode -= VM::FLAG_INTERACTIVE;
                    break;
                }
                else if (command.substr(0, 7) == "advance" && command.size() >= 9)
                {
                    std::string num = command.substr(8);
                    if(num.empty() || ((!isdigit(num[0])) && (num[0] != '-') && (num[0] != '+')))
                    {
                        std::cerr << "Give a correct number" << std::endl;
                        command = "";
                    }
                    else
                    {
                        int n = abc::strTo<int>(num);
                        if (n <= 0)
                        {
                            std::cerr << "A number < 0 is considered invalid" << std::endl;
                            command = "";
                        }
                        else
                            { m_interactive_advance = n; }
                    }
                }
                else if (command == "clear")
                {
                    #ifdef RUNNING_WIN
                    system("cls");
                    #endif // RUNNING_WIN
                    #ifdef RUNNING_POSIX
                    system("clear");
                    #endif // RUNNING_POSIX
                    command = "";
                }
                else
                {
                    std::cerr << "Unrecognized command `" << command << "`" << std::endl;
                    command = "";
                }
            }
            std::cerr << std::endl;
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
        m_debug_mode = mode;
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
            addr_t old_ip = 0;
            for (m_ip=0; m_ip < m_bytecode.size(); ++m_ip)
            {
                inst_t instruction = readByte(m_ip);
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "[" << m_ip << "] " << abc::hexstr((unsigned) instruction) << " ";

                if (INST_INT_2B <= instruction && instruction <= INST_DEL_VAR)
                    { exec_handleDataTypesDecl(instruction); }
                else if (INST_STORE_VAR <= instruction && instruction <= INST_POP)
                    { exec_handleSegments(instruction); }
                else if (instruction == INST_HALT)
                {
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "halt" << std::endl;
                    break;
                }
                else if (instruction == INST_PROCEDURE)
                    { exec_handleBuiltins(); }
                else
                {
                    if (instruction != 0x00)
                        { throw std::runtime_error("Can not identify the instruction " + abc::hexstr((unsigned) instruction)); }
                }

                if (m_debug_mode & VM::FLAG_INTERACTIVE && (m_interactive_advance == 0 || m_interactive_advance <= old_ip))
                {
                    if (m_interactive_advance != 0)
                        { m_interactive_advance = old_ip = 0; }
                    interactiveMode(instruction);
                }
                else if (m_debug_mode & VM::FLAG_INTERACTIVE && m_interactive_advance > old_ip)
                    { interactiveMode(instruction, /* displayOnly= */ true); }

                ++old_ip;
            }
            if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << std::endl << std::endl;

            return 0;
        }
        else
            { throw std::logic_error("Can not run if no bytecode were given"); }
    }

    ValueStack_t& VM::getStack()
    {
        return m_stack;
    }

    VarStack_t& VM::getVariables()
    {
        return m_variables;
    }

    void VM::saveBytecode(const std::string& filename)
    {
        std::ofstream output(filename, std::ios::binary);
        output.write((char*)&m_bytecode[0], m_bytecode.size());
        output.close();
    }

}  // namespace kafe

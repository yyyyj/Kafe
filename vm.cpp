#include <iostream>
#include <string.h>

#include "vm.hpp"

namespace kafe
{

    VM::VM() :
        m_stack_size(0)
        , m_debug(false)
    {}

    VM::~VM() {}

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
        m_variables.clear();
        m_segments.clear();
    }

    bcval_t VM::getByte(bytecode_t& bytecode, std::size_t i)
    {
        if (i < bytecode.size())
            return bytecode[i];
        throw std::runtime_error("Index out of range, can not get next byte ! => Malformed bytecode");
    }

    int VM::getXBytesInt(bytecode_t& bytecode, std::size_t& i, unsigned X)
    {
        int v = getByte(bytecode, ++i);
        for (unsigned k=1; k < X; ++k)
            { v = (v << 8) + getByte(bytecode, ++i); }
        return v;
    }

    std::string VM::readString(bytecode_t& bytecode, std::size_t& i, std::size_t strSize)
    {
        std::string work = "";
        ++i;
        for (std::size_t j=i; i - j < strSize; ++i)
            { work += getByte(bytecode, i); }
        --i;
        return work;
    }

    std::string VM::getSegmentName(bytecode_t& bytecode, std::size_t& i)
    {
        std::size_t str_size = getByte(bytecode, ++i);
        if (str_size > 0)
            { return readString(bytecode, i, str_size); }
        else
            { throw std::logic_error("Invalid size given for the segment name to fetch"); }
    }

    void VM::goToSegmentPosition(const std::string& segmentName, std::size_t& i)
    {
        if (m_segments.find(segmentName) != m_segments.end())
            { i = m_segments[segmentName] - 1; }  // -1 because we do that before an iteration end, so we will do ++i just after
        else
            { throw std::runtime_error("Can not jump to an undefined segment"); }
    }

    void VM::pushCallStack(const std::string& segmentName, std::size_t lastPos)
    {
        // we need to keep track of what segment we jumped to, from which position,
        // to be able to go able to the caller position easily, and continue the execution
        if (m_call_stack.size() == 0 || m_call_stack[m_call_stack.size() - 1].segmentName != segmentName)
        {
            Call call_element;
            call_element.lastPosition.push_back(lastPos);
            call_element.segmentName = segmentName;
            m_call_stack.push_back(call_element);
        }
        else
            { m_call_stack[m_call_stack.size() - 1].lastPosition.push_back(lastPos); }

        if (m_debug) std::cout << "    call stack: " << m_call_stack[m_call_stack.size() - 1].lastPosition[m_call_stack[m_call_stack.size() - 1].lastPosition.size() - 1] << " " << m_call_stack[m_call_stack.size() - 1].segmentName << std::endl;
    }

    bool VM::canValueCompareTo(Value val, bool c)
    {
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

    void VM::builtins(bcval_t instruction)
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

    int VM::exec(bytecode_t bytecode)
    {
        clear();

        for (std::size_t i=0; i < bytecode.size(); ++i)
        {
            bcval_t instruction = getByte(bytecode, i);
            if (m_debug) std::cout << i << " ";

            switch (instruction)
            {
                case INST_INT:
                {
                    if (m_debug) std::cout << "int" << std::endl;

                    Value v;
                    v.type = TYPE_INT;
                    v.intValue = getXBytesInt(bytecode, i);
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

                    std::size_t str_size = getXBytesInt(bytecode, i);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_STRING;
                        a.stringValue = readString(bytecode, i, str_size);
                        push(a);
                    }
                    else
                        { throw std::logic_error("Invalid size given for the string to store"); }

                    break;
                }

                case INST_BOOL:
                {
                    if (m_debug)  std::cout << "bool" << std::endl;

                    Value a;
                    a.type = TYPE_BOOL;
                    a.boolValue = getByte(bytecode, ++i) > 0;
                    push(a);

                    break;
                }

                case INST_LIST:
                {
                    if (m_debug) std::cout << "list" << std::endl;

                    std::size_t nb_elements = getXBytesInt(bytecode, i);
                    Value c;
                    c.type = TYPE_LIST;
                    while (nb_elements != 0)
                    {
                        c.listValue.push_back(pop());
                        nb_elements--;
                    }

                    break;
                }

                case INST_VAR:
                {
                    if (m_debug) std::cout << "var" << std::endl;

                    std::size_t str_size = getByte(bytecode, ++i);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_VAR;
                        a.stringValue = readString(bytecode, i, str_size);
                        push(a);
                    }
                    else
                        { throw std::logic_error("Invalid size given for the variable name to store"); }

                    break;
                }

                case INST_STRUCT:
                {
                    if (m_debug) std::cout << "structure" << std::endl;

                    std::size_t str_size = getByte(bytecode, ++i);
                    if (str_size > 0)
                    {
                        Value a;
                        a.type = TYPE_STRUCT;
                        // getting the structure name
                        std::string name = readString(bytecode, i, str_size);
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

                    std::size_t str_size = getByte(bytecode, ++i);
                    std::string seg_name;
                    if (str_size > 0)
                        { seg_name = readString(bytecode, i, str_size); }
                    else
                        { throw std::logic_error("Invalid size for the segment name"); }

                    if (m_segments.find(seg_name) == m_segments.end())
                        { m_segments[seg_name] = i; }

                    std::size_t seg_size = getXBytesInt(bytecode, i);
                    if (seg_size > 0)
                        { i += seg_size; }
                    else
                        { throw std::logic_error("Invalid bloc count for the segment"); }

                    break;
                }

                case INST_DECL_SEG:
                {
                    if (m_debug) std::cout << "declare segment" << std::endl;

                    std::size_t str_size = getByte(bytecode, ++i);
                    std::string seg_name;
                    if (str_size > 0)
                        { seg_name = readString(bytecode, i, str_size); }
                    else
                        { throw std::logic_error("Invalid size for the segment name"); }

                    m_segments[seg_name] = getXBytesInt(bytecode, i);

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

                    std::size_t str_size = getByte(bytecode, ++i);
                    if (str_size > 0)
                    {
                        std::string v = readString(bytecode, i, str_size);
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
                        push(a); push(a);
                    }
                    else
                        { throw std::logic_error("Can not duplicate the last value of the stack if there isn't any"); }

                    break;
                }

                case INST_JUMP:
                {
                    if (m_debug) std::cout << "jump" << std::endl;

                    std::string seg_name = getSegmentName(bytecode, i);
                    std::size_t last_pos = i;
                    goToSegmentPosition(seg_name, i);
                    pushCallStack(seg_name, last_pos);

                    if (m_debug) std::cout << "    jumping to : " << seg_name << std::endl;

                    break;
                }

                case INST_JUMP_IF:
                {
                    if (m_debug) std::cout << "jump if" << std::endl;

                    Value a = pop();
                    if (canValueCompareTo(a, true))
                    {
                        std::string seg_name = getSegmentName(bytecode, i);
                        std::size_t last_pos = i;
                        goToSegmentPosition(seg_name, i);
                        pushCallStack(seg_name, last_pos);

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
                        std::string seg_name = getSegmentName(bytecode, i);
                        std::size_t last_pos = i;
                        goToSegmentPosition(seg_name, i);
                        pushCallStack(seg_name, last_pos);

                        if (m_debug) std::cout << "    jumping to : " << seg_name << std::endl;
                    }

                    break;
                }

                case INST_RET:
                {
                    if (m_debug) std::cout << "ret" << std::endl;

                    if (m_call_stack.size() > 0)
                    {
                        i = abc::pop(m_call_stack[m_call_stack.size() - 1].lastPosition, -1);
                        if (m_call_stack[m_call_stack.size() - 1].lastPosition.size() == 0)
                            abc::pop_no_return(m_call_stack, -1);
                    }
                    else
                        { throw std::logic_error("Can not return from a non-segment !"); }

                    break;
                }

                case INST_PROCEDURE:
                {
                    // we implement the procedure in another function, using a special code
                    // in order to be able to have (1st) more procedures and (2nd) a cleaner code
                    builtins(getByte(bytecode, ++i));
                    break;
                }

                default:
                {
                    if (instruction != 0x00)
                        { throw std::runtime_error("Can not identify the instruction " + abc::str((unsigned) instruction)); }
                }
            }
        }

        return 0;
    }

    // int VM::execSegment(char* bytecode, char* segment_name) { return 0; }

    void VM::setDebug(bool debug)
    {
        m_debug = debug;
    }

    ValueStack_t& VM::getStack()
    {
        return m_stack;
    }

}  // namespace kafe

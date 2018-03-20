/*
 * Kafe - A programming language running on a VM
 * 
 * Copyright (c) 2018 SuperFola and the Kafe open source project
 * Licensed under MPL-2.0
 * 
 * This notice may not be removed or altered from any source ditribution
 * 
 * See https://superfola.github.io/Kafe/CONTRIBUTORS.txt for the list of Kafe project authors
 * See https://superfola.github.io/Kafe/LICENSE for license information
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <termcolor.hpp>

#ifdef max
    #undef max  // macro complificting with std::max
#endif  // max

#include <kafe/vm/vm.hpp>
#include <kafe/vm/vm_lib.hpp>

#ifdef _MSC_VER
    // if compiling with visual studio, disable those warnings
    #pragma warning (disable: 4244)  // conversion from addr_t to int, possible loss of data
    #pragma warning (disable: 4334)  // shift result of 32 bits implicitly converted in 64 bits
#endif

namespace kafe
{

    using namespace abc;

    VM::VM() : m_stack_size(0), m_ip(0), m_bbm(m_ip, m_bytecode, m_errh), m_debug_mode(0), m_interactive_advance(0), m_has_been_dirty_clean(false) {}

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
        if (m_stack_size - 1 >= 0)
            return abc::pop(m_stack, --m_stack_size);
        else
            m_errh.raiseException(Exception::CRITIC, "Can not pop from an empty value stack", m_ip);
    }

    void VM::dirtyClear()
    {
        // cleaning the VM to run it again without creating a new instance
        m_stack_size = m_ip = m_interactive_advance = 0;

        m_stack.clear();
        m_call_stack.clear();
        m_variables.clear();
        m_errh.clear();

        m_has_been_dirty_clean = true;
    }

    void VM::clear()
    {
        dirtyClear();

        m_struct_definitions.clear();
    }

    void VM::loadLib()
    {
        // load the default procedures for the vm
        StdLibVM::load(m_fdb);
    }

    VarFound VM::findVar(const str_t& varName)
    {
        if (m_call_stack.size() == 0)
            return (m_variables.find(varName) != m_variables.end()) ? VarFound::InCurrentScopeGlobal : VarFound::NotFound;
        // if we didn't found the variable in the current scope, search for it in the upper scope
        if (m_call_stack[m_call_stack.size() - 1].vars.find(varName) == m_call_stack[m_call_stack.size() - 1].vars.end())
            return (m_variables.find(varName) != m_variables.end()) ? VarFound::NotInCurrentScopeButInGlobal : VarFound::NotFound;
        return VarFound::InCurrentScopeNotGlobal;
    }

    Value VM::getVar(const str_t& varName, VarFound vf)
    {
        // we can get a var from the upper scope, but we search it in the current scope before looking in the global scope
        if (vf == VarFound::InCurrentScopeGlobal || vf == VarFound::NotInCurrentScopeButInGlobal)
            return m_variables[varName];
        else if (vf == VarFound::InCurrentScopeNotGlobal)
            return m_call_stack[m_call_stack.size() - 1].vars[varName];
        // vf == VarFound::NotFound
        m_errh.raiseException(Exception::CRITIC, "Can not get a missing variable `" + varName + "`. You are misusing the VM, please refer to the documentation (I have written it my self and I know there is anything you need in it :D )", m_ip);
    }

    Value& VM::getRefVar(const str_t& varName, VarFound vf)
    {
        if (vf == VarFound::InCurrentScopeGlobal)
        {
            // the variable is in the global scope, and we are in the global scope, no problems
            // we can read / write on it
            if (!m_variables[varName].isConst())
                return m_variables[varName];
            m_errh.raiseException(Exception::CRITIC, "Can not modify a const variable `" + varName + "`", m_ip);
        }
        else if (vf == VarFound::NotInCurrentScopeButInGlobal)
        {
            // we are trying to get a reference on a variable outside our current scope
            // probably to modify it. we need to check if the variable is in the nonlocals vars list
            std::vector<str_t>& refs = m_call_stack[m_call_stack.size() - 1].refs_to_gscope;
            if (std::find(refs.begin(), refs.end(), varName) != refs.end())
            {
                if (!m_call_stack[m_call_stack.size() - 1].vars[varName].isConst())
                    return m_call_stack[m_call_stack.size() - 1].vars[varName];
                m_errh.raiseException(Exception::CRITIC, "Can not modify a const variable `" + varName + "`", m_ip);
            }
            m_errh.raiseException(Exception::CRITIC, "Can not get the wanted variable : `" + varName + "`, try declaring it as nonlocal", m_ip);
        }
        else if (vf == VarFound::InCurrentScopeNotGlobal)
        {
            // we found the variable in the current scope
            if (!m_call_stack[m_call_stack.size() - 1].vars[varName].isConst())
                return m_call_stack[m_call_stack.size() - 1].vars[varName];
            m_errh.raiseException(Exception::CRITIC, "Can not modify a const variable `" + varName + "`", m_ip);
        }
        // vf == VarFound::NotFound
        m_errh.raiseException(Exception::CRITIC, "Can not get a missing variable `" + varName + "`. You are misusing the VM, please refer to the documentation (I have written it my self and I know there is anything you need in it :D )", m_ip);
    }

    void VM::setVar(const str_t& varName, Value v, VarFound vf, bool is_const)
    {
        // we are changing the value of a variable
        if (vf != VarFound::NotFound)
        {
            // by calling getRefVar it will automatically resolve the visibility of the variable
            Value& val = getRefVar(varName, vf);
            val = v;
            val.is_const = is_const;
        }
        else
        {
            // we create it
            if (m_call_stack.size() == 0)
            {
                if (!m_variables[varName].isConst())
                    m_variables[varName] = v;
                else
                    m_errh.raiseException(Exception::CRITIC, "Can not modify a const variable", m_ip);
            }
            else
            {
                if (!m_call_stack[m_call_stack.size() - 1].vars[varName].isConst())
                    m_call_stack[m_call_stack.size() - 1].vars[varName] = v;
                else
                    m_errh.raiseException(Exception::CRITIC, "Can not modify a const variable", m_ip);
            }
        }
    }

    void VM::delVar(const str_t& varName)
    {
        if (m_call_stack.size() == 0)
            m_variables.erase(m_variables.find(varName));
        else
            m_call_stack[m_call_stack.size() - 1].vars.erase(m_call_stack[m_call_stack.size() - 1].vars.find(varName));
    }

    void VM::performJump(bool registerCall)
    {
        addr_t last_pos;
        // keep the last value of the instruction pointer, we'll need it
        last_pos = m_ip;
        // jump to the segment
        Value p = pop();
        if (p.type != ValueType::Addr)
            m_errh.raiseException(Exception::LOGIC, "Can not jump to something which isn't an address", m_ip);
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
                if (m_debug_mode & VM::FLAG_EXPERIMENTAL)
                {
                    while (lc.lastStackSize - m_stack.size() > 1)
                        pop();
                }
                else if (m_debug_mode & VM::FLAG_BASIC_DEBUG)
                    std::cerr << "[WARNING] entering the garbage collector (not implemented ATM), with lc.lastStackSize="
                              << lc.lastStackSize << " and m_stack.size()=" << m_stack.size() << std::endl;
            }
        }
        else
            m_errh.raiseException(Exception::MALFORMED, "Can not return from a non-segment", m_ip);
    }

    /// ------------------------------------------------------------
    void VM::exec_handleDataTypesDecl(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_INT_2B:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "int 2B" << std::endl;

                Value v = m_bbm.get2BytesInt();
                push(v);

                break;
            }

            case INST_INT_4B:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "int 4B" << std::endl;

                Value v = m_bbm.get4BytesInt();
                push(v);

                break;
            }

            case INST_INT_8B:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "int 8B" << std::endl;

                Value v = m_bbm.get8BytesInt();
                push(v);

                break;
            }

            case INST_DOUBLE:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "double" << std::endl;

                Value v = m_bbm.getDouble();
                push(v);

                break;
            }

            case INST_STR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "str" << std::endl;

                Value v = m_bbm.getString();
                push(v);

                break;
            }

            case INST_BOOL:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "bool" << std::endl;

                Value v = m_bbm.getBool();
                push(v);

                break;
            }

            case INST_ADDR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "addr" << std::endl;

                Value v = m_bbm.getAddr();
                push(v);

                break;
            }

            case INST_LIST:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "list" << std::endl;

                smol_uint_t nb_elements = m_bbm.read4BytesInt();
                Value c(ValueType::List);
                c.getRef<list_t>().reserve(nb_elements);
                while (nb_elements != 0)
                {
                    c.getRef<list_t>().insert(c.getRef<list_t>().begin(), pop());
                    nb_elements--;
                }

                break;
            }

            case INST_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "var" << std::endl;

                Value v = m_bbm.getString();
                v.type = ValueType::Var;
                push(v);

                break;
            }

            case INST_EMPTY:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "empty value" << std::endl;

                Value v(ValueType::Empty);
                push(v);

                break;
            }

            case INST_STRUCT:
            case INST_DECL_STRUCT:
            case INST_STRUCT_GETM:
            case INST_STRUCT_SETM:
            case INST_STRUCT_HASM:
            case INST_STRUCT_TID:
            {
                exec_handleStructures(instruction);
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
                str_t struct_name = m_bbm.readString();
                // to take the default data in it and fill the new object with those
                if (m_struct_definitions.find(struct_name) != m_struct_definitions.end())
                {
                    // init the newly created structure from its "parent"
                    a.getRef<Structure>() = m_struct_definitions[struct_name];
                    // push the given arguments
                    micro_uint_t nb_args = m_bbm.read2BytesInt();
                    for (micro_uint_t j = 0; j < nb_args; ++j)
                    {
                        Value name = pop();
                        Value val = pop();

                        // we check that the given "name" is a valid variable name
                        if (name.type == ValueType::Var)
                        {
                            // and we perform some type checking
                            StructElem* pse = a.getRef<Structure>().findMember(name.get<str_t>());
                            if (pse != nullptr)
                            {
                                if (pse->val.type == val.type)
                                    a.getRef<Structure>().add(name.get<str_t>(), val);
                                else
                                    m_errh.raiseException(Exception::LOGIC, "Type error while trying to set an argument of a structure", m_ip);
                            }
                            else
                                m_errh.raiseException(Exception::RUNTIME, "Can not set a non-member of a structure using a structure declaration", m_ip);
                        }
                        else
                            m_errh.raiseException(Exception::LOGIC, "The name of the member to set in the given structure isn't a string", m_ip);
                    }
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not use an undefined structure", m_ip);
                push(a);

                break;
            }

            case INST_DECL_STRUCT:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "declare structure" << std::endl;

                str_t name = m_bbm.readString();
                micro_uint_t pairs_nb = m_bbm.read2BytesInt();
                m_struct_definitions[name] = Structure();
                for (micro_uint_t j = 0; j < pairs_nb; ++j)
                {
                    Value name = pop();
                    Value val = pop();

                    if (name.type == ValueType::Var)
                        m_struct_definitions[name.get<str_t>()].add(name.get<str_t>(), val);
                    else
                        m_errh.raiseException(Exception::LOGIC, "Expecting a variable when declaring a structure's member", m_ip);
                }

                break;
            }

            case INST_STRUCT_GETM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure get member" << std::endl;

                str_t name = m_bbm.readString();
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                {
                    str_t member = m_bbm.readString();
                    StructElem* pse = getRefVar(name, vf).getRef<Structure>().findMember(member);
                    if (pse != nullptr)
                        push(pse->val);
                    else
                        m_errh.raiseException(Exception::RUNTIME, "Can not get a non-existing member of a structure", m_ip);
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not get a member of a non-existing structure", m_ip);

                break;
            }

            case INST_STRUCT_SETM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure set member" << std::endl;

                str_t name = m_bbm.readString();
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                {
                    str_t member = m_bbm.readString();
                    getRefVar(name, vf).getRef<Structure>().set(member, pop());
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not set a member of a non-existing structure", m_ip);

                break;
            }

            case INST_STRUCT_HASM:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure has member" << std::endl;

                str_t name = m_bbm.readString();
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                {
                    str_t member = m_bbm.readString();
                    if (getRefVar(name, vf).getRef<Structure>().findMember(member) != nullptr)
                        push(Value(ValueType::Bool, true));
                    else
                        push(Value(ValueType::Bool, false));
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not get a member of a non-existing structure", m_ip);

                break;
            }

            case INST_STRUCT_HASPARENT:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "struct has parent" << std::endl;

                str_t parent_name = m_bbm.readString();
                VarFound vf = findVar(parent_name);
                if (vf != VarFound::NotFound)
                {
                    // the parent_name thing is an instantiated structure
                    str_t child = m_bbm.readString();
                    VarFound vf2 = findVar(child);
                    if (vf2 != VarFound::NotFound)
                        push(Value(ValueType::Bool, getRefVar(child, vf2).getRef<Structure>().hasParent(getRefVar(parent_name, vf).getRef<Structure>())));
                    else
                        m_errh.raiseException(Exception::RUNTIME, "Can not find the structure to perform the parenting check", m_ip);
                }
                else
                {
                    // the wanted structure isn't instantiated
                    if (m_struct_definitions.find(parent_name) != m_struct_definitions.end())
                    {
                        str_t child = m_bbm.readString();
                        VarFound vf2 = findVar(child);
                        if (vf2 != VarFound::NotFound)
                            push(Value(ValueType::Bool, getRefVar(child, vf2).getRef<Structure>().hasParent(m_struct_definitions[parent_name])));
                        else
                            m_errh.raiseException(Exception::RUNTIME, "Can not find the structure to perform the parenting check", m_ip);
                    }
                    else
                        m_errh.raiseException(Exception::LOGIC, "Can not find the wanted structure to determine if another one is its child or not", m_ip);
                }

                break;
            }

            case INST_STRUCT_TID:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "structure type id" << std::endl;

                str_t name = m_bbm.readString();
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                {
                    Value tid(ValueType::Int);
                    Structure& s = getRefVar(name, vf).getRef<Structure>();
                    tid.set<int_t>(s.struct_id[s.struct_id.size() - 1]);
                    push(tid);
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not get a member of a non-existing structure", m_ip);

                break;
            }
        }
    }

    void VM::exec_handleVariableThings(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_STORE_DYN:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "store dyn" << std::endl;

                Value var_name = pop();
                Value val = pop();

                if (var_name.type == ValueType::Var)
                    setVar(var_name.get<str_t>(), val, findVar(var_name.get<str_t>()));
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not store a value into a non-variable", m_ip);

                break;
            }

            case INST_STORE_CST:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "store cst" << std::endl;

                Value var_name = pop();
                Value val = pop();

                if (var_name.type == ValueType::Var)
                    setVar(var_name.get<str_t>(), val, findVar(var_name.get<str_t>()), /* is_const */ true);
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not store a value into a non-variable", m_ip);

                break;
            }

            case INST_LOAD_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "push var" << std::endl;

                // we read the size of the var name and read it
                str_t name = m_bbm.readString();
                // if the variable can be found, push it on the stack
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                    push(getVar(name, vf));
                else
                    m_errh.raiseException(Exception::RUNTIME, "Can not push an undefined variable onto the stack", m_ip);

                break;
            }

            case INST_DEL_VAR:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "delete variable" << std::endl;

                str_t name = m_bbm.readString();
                if (findVar(name) != VarFound::NotFound)
                    delVar(name);
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not delete a non-existing variable", m_ip);

                break;
            }

            case INST_NONLOCAL:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "nonlocal" << std::endl;

                str_t name = m_bbm.readString();
                if (findVar(name) != VarFound::NotFound)
                {
                    if (m_call_stack.size() != 0)
                        m_call_stack[m_call_stack.size() - 1].refs_to_gscope.push_back(name);
                    else
                        m_errh.raiseException(Exception::LOGIC, "Can not declare a global scope variable as nonlocal in the global scope : `" + name + "`", m_ip);
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not delete a non-existing variable", m_ip);

                break;
            }

            case INST_GET_TYPE:
            {
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "get type" << std::endl;

                str_t name = m_bbm.readString();
                VarFound vf = findVar(name);
                if (vf != VarFound::NotFound)
                {
                    Value str_type(ValueType::String);
                    str_type.set<str_t>(convertTypeToString(getVar(name, vf).type));
                    push(str_type);
                }
                else
                    m_errh.raiseException(Exception::LOGIC, "Can not delete a non-existing variable", m_ip);

                break;
            }
        }
    }

    void VM::exec_handleListThings(inst_t instruction)
    {
        switch (instruction)
        {
            case INST_SIZE_LST:
            {
                break;
            }

            case INST_POP_LST:
            {
                break;
            }

            case INST_APPEND_LST:
            {
                break;
            }

            case INST_GNTH_LST:
            {
                break;
            }

            case INST_SNTH_LST:
            {
                break;
            }

            case INST_GSLICE_LST:
            {
                break;
            }

            case INST_SSLICE_LST:
            {
                break;
            }

            case INST_CONS_LST:
            {

                break;
            }
        }
    }

    void VM::exec_handleSegments(inst_t instruction)
    {
        switch (instruction)
        {
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
                    m_errh.raiseException(Exception::LOGIC, "Can not duplicate the last value of the stack if there isn't any", m_ip);

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
                    pop();  // remove the address from the stack

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
                    pop();  // remove the address from the stack

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
        micro_uint_t instruction = m_bbm.read2BytesInt();

        switch (instruction)
        {
            case INST_ADD:
            case INST_SUB:
            case INST_MUL:
            case INST_GR:
            {
                Value b = pop();
                Value a = pop();
                Value r = StdLibVM::procName(instruction);
                addr_t last = m_ip;

                if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << r.get<str_t>() << std::endl;

                if (r.type != ValueType::Exception)
                {
                    Value c = m_fdb[r.get<str_t>()].call<Value, const Value&, const Value&>(a, b);

                    if (c.type != ValueType::Exception)
                        push(c);
                    else
                    {
                        c.getRef<Exception>().setLine(last);
                        m_errh.raiseException(c.get<Exception>());
                    }
                }
                else
                {
                    r.getRef<Exception>().setLine(last);
                    m_errh.raiseException(r.get<Exception>());
                }

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
                m_errh.raiseException(Exception::MALFORMED, "Invalid byte used to identify a non-existing procedure : " +
                                         str((unsigned) instruction), m_ip);
            }
        }
    }
    /// -----------------------------------------------------------

    void VM::interactiveMode(inst_t instruction, bool displayOnly)
    {
        // display stack + variables
        std::cerr << std::endl << "IP = " << std::setw(4) << termcolor::cyan << m_ip << termcolor::reset << " | Bytecode size = " << std::setw(5) << termcolor::cyan << m_bytecode.size() << termcolor::reset << " | "
                  << "Instruction = " << hexstr((unsigned) instruction)         << std::endl
                  << "Stack                     | Variables                   " << std::endl
                  << "--------------------------|-----------------------------" << std::endl;
        VarStack_t::iterator it = m_variables.begin();
        for (std::size_t i=0; i < std::max(m_stack.size(), m_variables.size()); ++i)
        {
            if (i < m_stack.size())
                std::cerr << std::setw(6) << termcolor::green << convertTypeToString(m_stack[i].type) << termcolor::reset << " " << std::setw(18) << termcolor::yellow << m_stack[i] << termcolor::reset;
            else
                std::cerr << "                         ";
            std::cerr << " | ";
            if (i < m_variables.size())
            {
                std::ostringstream out;
                out << std::setw(12) << it->first << " = " << std::setw(6) << termcolor::green << convertTypeToString(it->second.type) << termcolor::reset << " " << termcolor::yellow << it->second << termcolor::reset;
                if (it->second.is_const)
                    out << " (CONST)";
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
                std::cerr << std::endl << termcolor::green << "> " << termcolor::yellow;
                std::getline(std::cin, command);
                std::cerr << termcolor::reset;

                if (command == "help")
                {
                    std::cerr << "Type `continue` to advance to the next relevant bytecode" << std::endl
                              << "     `break` to quit the interactive mode and continue the execution" << std::endl
                              << "     `advance x`, x a number between 0 and the bytecode size to read x byte without prompting again" << std::endl
                              << "     `cslevel` get call stack level" << std::endl
                              << "     `clear` to clear the screen" << std::endl
                        ;
                    command = "";
                }
                else if (command == "continue")
                    break;
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
                        int n = strTo<int>(num);
                        if (n <= 0)
                        {
                            std::cerr << "A number < 0 is considered invalid" << std::endl;
                            command = "";
                        }
                        else
                            m_interactive_advance = n;
                    }
                }
                else if (command == "cslevel")
                {
                    std::cerr << "Call stack level : " << m_call_stack.size() << std::endl;
                    command = "";
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
                    std::cerr << termcolor::red << "Unrecognized command `" << command << "`" << termcolor::reset << std::endl;
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
            throw std::runtime_error("Can not open the given file");
        std::ifstream::pos_type pos = ifs.tellg();
        // reserve the appropriate size
        std::vector<char> temp(pos);
        // seek to the beginning of the file and read
        ifs.seekg(0, std::ios::beg);
        ifs.read(&temp[0], pos);
        ifs.close();

        bytecode_t bytes(pos);
        for (std::size_t i=0; i < pos; ++i)
            bytes[i] = (inst_t) temp[i];

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
        // load the default procedures if the table if empty
        if (m_fdb.size() == 0)
            loadLib();
        m_bytecode.load(bytecode);
        m_stack.reserve(m_bytecode.size() * 2);
        m_call_stack.reserve((m_bytecode.size() > 36) ? ((m_bytecode.size() > 128) ? ((m_bytecode.size() > 512) ? m_bytecode.size() * 2 : 1024) : 256) : 64);
    }

    int VM::exec()
    {
        if (m_bytecode.size() != 0)
        {
            // if the VM is runned multiple times with the same bytecode, just keep a few things
            if (!m_has_been_dirty_clean)
                dirtyClear();

            addr_t old_ip = 0;
            for (m_ip=0; m_ip < m_bytecode.size(); ++m_ip)
            {
                inst_t instruction = m_bbm.readByte(m_ip);
                if (m_debug_mode & VM::FLAG_BASIC_DEBUG)
                    std::cerr << "[" << m_ip << "] " << hexstr(unsigned(instruction)) << " ";

                if (INST_INT_2B <= instruction && instruction <= INST_STRUCT_TID)
                    exec_handleDataTypesDecl(instruction);
                else if (INST_STORE_DYN <= instruction && instruction <= INST_GET_TYPE)
                    exec_handleVariableThings(instruction);
                else if (INST_SIZE_LST <= instruction && instruction <= INST_CONS_LST)
                    exec_handleListThings(instruction);
                else if (INST_DUP <= instruction && instruction <= INST_POP)
                    exec_handleSegments(instruction);
                else if (instruction == INST_HALT)
                {
                    if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << "halt" << std::endl;
                    break;
                }
                else if (instruction == INST_PROCEDURE)
                    exec_handleBuiltins();
                else
                {
                    if (instruction != 0x00)
                        m_errh.raiseException(Exception::MALFORMED, "Can not identify the instruction " + hexstr(unsigned(instruction)), m_ip);
                }

                if (m_debug_mode & VM::FLAG_INTERACTIVE && (m_interactive_advance == 0 || m_interactive_advance <= old_ip))
                {
                    if (m_interactive_advance != 0)
                        m_interactive_advance = old_ip = (addr_t) 0;
                    interactiveMode(instruction);
                }
                else if (m_debug_mode & VM::FLAG_INTERACTIVE && m_interactive_advance > old_ip)
                    interactiveMode(instruction, /* displayOnly= */ true);
                
                if (!m_errh.empty())
                    m_errh.displayTraceback();

                ++old_ip;
            }
            if (m_debug_mode & VM::FLAG_BASIC_DEBUG) std::cerr << std::endl << std::endl;

            // reset the flag
            m_has_been_dirty_clean = false;

            return 0;
        }
        else
            throw std::logic_error("Can not run if no byte codes were given");
    }

    void VM::registerFunction(const std::string& name, functionPtr fct)
    {
        m_fdb_user.add(name, fct);
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
        bytecode_t bytecode(m_bytecode.get());
        output.write((char*)&bytecode[0], bytecode.size());
        output.close();
    }

}  // namespace kafe

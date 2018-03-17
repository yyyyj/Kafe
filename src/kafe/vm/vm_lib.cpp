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

#include <kafe/vm/vm_lib.hpp>

namespace kafe
{
    namespace StdLibVM
    {

        using namespace abc;

        Value procName(micro_uint_t inst)
        {
            if (inst > 0)
            {
                Value s(ValueType::String);
                s.set<str_t>(inst_to_name[inst - 1]);
                return s;
            }
            Value exc(ValueType::Exception);
            exc.set<Exception>(Exception(Exception::CRITIC, "Can not find the procedure corresponding to the byte code 0x0000", 0));
            return exc;
        }

        Value _doStuff(const Value&, const Value&) { return Value(ValueType::Bool, false); }

        Value _add(const Value& a, const Value& b)
        {
            Value exc(ValueType::Exception);

            if (a.type == b.type)
            {
                if (a.type == ValueType::Int)
                {
                    Value c(ValueType::Int);
                    c.set<int_t>(a.get<int_t>() + b.get<int_t>());
                    return c;
                }
                else if (a.type == ValueType::Double)
                {
                    Value c(ValueType::Double);
                    c.set<double>(a.get<double>() + b.get<double>());
                    return c;
                }
                else if (a.type == ValueType::String)
                {
                    Value c(ValueType::String);
                    c.set<str_t>(a.get<str_t>() + b.get<str_t>());
                    return c;
                }
                else if (a.type == ValueType::List)
                {
                    Value c(ValueType::List);
                    for (std::size_t i = 0; i < a.get<list_t>().size(); ++i)
                        c.getRef<list_t>().push_back(a.get<list_t>()[i]);
                    for (std::size_t i = 0; i < b.get<list_t>().size(); ++i)
                        c.getRef<list_t>().push_back(b.get<list_t>()[i]);
                    return c;
                }
                exc.set<Exception>(Exception(Exception::LOGIC, "Can not add two " + convertTypeToString(a.type), 0));
            }
            else if (a.type == ValueType::Int && b.type == ValueType::Double)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<int_t>() + b.get<double>());
                return c;
            }
            else if (a.type == ValueType::Double && b.type == ValueType::Int)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<double>() + b.get<int_t>());
                return c;
            }
            exc.set<Exception>(Exception(Exception::LOGIC, "Can not add two variables of heterogeneous types", 0));
            return exc;
        }

        Value _sub(const Value& a, const Value& b)
        {
            Value exc(ValueType::Exception);

            if (a.type == b.type)
            {
                if (a.type == ValueType::Int)
                {
                    Value c(ValueType::Int);
                    c.set<int_t>(a.get<int_t>() - b.get<int_t>());
                    return c;
                }
                else if (a.type == ValueType::Double)
                {
                    Value c(ValueType::Double);
                    c.set<double>(a.get<double>() - b.get<double>());
                    return c;
                }
                exc.set<Exception>(Exception(Exception::LOGIC, "Can not substract two " + convertTypeToString(a.type), 0));
            }
            else if (a.type == ValueType::Int && b.type == ValueType::Double)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<int_t>() - b.get<double>());
                return c;
            }
            else if (a.type == ValueType::Double && b.type == ValueType::Int)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<double>() - b.get<int_t>());
                return c;
            }
            exc.set<Exception>(Exception(Exception::LOGIC, "Can not substract two variables of heterogeneous types", 0));
            return exc;
        }

        Value _mul(const Value& a, const Value& b)
        {
            Value exc(ValueType::Exception);

            if (a.type == b.type)
            {
                if (a.type == ValueType::Int)
                {
                    Value c(ValueType::Int);
                    c.set<int_t>(a.get<int_t>() * b.get<int_t>());
                    return c;
                }
                else if (a.type == ValueType::Double)
                {
                    Value c(ValueType::Double);
                    c.set<double>(a.get<double>() * b.get<double>());
                    return c;
                }
                exc.set<Exception>(Exception(Exception::LOGIC, "Can not multiply two " + convertTypeToString(a.type), 0));
            }
            else if (a.type == ValueType::Int && b.type == ValueType::Double)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<int_t>() * b.get<double>());
                return c;
            }
            else if (a.type == ValueType::Double && b.type == ValueType::Int)
            {
                Value c(ValueType::Double);
                c.set<double>(a.get<double>() * b.get<int_t>());
                return c;
            }
            exc.set<Exception>(Exception(Exception::LOGIC, "Can not multiply two variables of heterogeneous types", 0));
            return exc;
        }

        Value _gr(const Value& a, const Value& b)
        {
            return Value(ValueType::Bool, a >= b);
        }


        void load(FunctionDatabase& fdb)
        {
            fdb.add("",       &_doStuff);  // just for the alignment
            fdb.add("add",    &_add);
            fdb.add("sub",    &_sub);
            fdb.add("div",    &_doStuff); // &_div);
            fdb.add("mul",    &_mul);
            fdb.add("mod",    &_doStuff); // &_mod);
            fdb.add("inc",    &_doStuff); // &_inc);
            fdb.add("dec",    &_doStuff); // &_dec);
            fdb.add("neg",    &_doStuff); // &_neg);
            fdb.add("binand", &_doStuff); // &_binand);
            fdb.add("binnor", &_doStuff); // &_binnor);
            fdb.add("binnot", &_doStuff); // &_binnot);
            fdb.add("lshift", &_doStuff); // &_lshift);
            fdb.add("rshift", &_doStuff); // &_rshift);
            fdb.add("binxor", &_doStuff); // &_binxor);
            fdb.add("and",    &_doStuff); // &_and);
            fdb.add("or",     &_doStuff); // &_or);
            fdb.add("not",    &_doStuff); // &_not);
            fdb.add("lw",     &_doStuff); // &_lw);
            fdb.add("le",     &_doStuff); // &_le);
            fdb.add("gr",     &_gr);
            fdb.add("ge",     &_doStuff); // &_ge);
            fdb.add("eq",     &_doStuff); // &_eq);
            fdb.add("ne",     &_doStuff); // &_ne);
        }
    }
}
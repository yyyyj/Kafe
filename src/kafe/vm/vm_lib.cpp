#include "vm_lib.hpp"

namespace kafe
{
    namespace StdLibVM
    {
        Value procName(int2B_t inst)
        {
            if (inst > 0)
                return Value(ValueType::String, inst_to_name[inst - 1]);
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
                    c.set<int8B_t>(a.get<int8B_t>() + b.get<int8B_t>());
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
                    c.set<std::string>(a.get<std::string>() + b.get<std::string>());
                    return c;
                }
                else if (a.type == ValueType::List)
                {
                    Value c(ValueType::List);
                    for (std::size_t i = 0; i < a.get<Value::list_t>().size(); ++i)
                        c.getRef<Value::list_t>().push_back(a.get<Value::list_t>()[i]);
                    for (std::size_t i = 0; i < b.get<Value::list_t>().size(); ++i)
                        c.getRef<Value::list_t>().push_back(b.get<Value::list_t>()[i]);
                    return c;
                }
                exc.set<Exception>(Exception(Exception::LOGIC, "Can not add two " + convertTypeToString(a.type), 0));
            }
            exc.set<Exception>(Exception(Exception::LOGIC, "Can not add two variables of heterogeneous types", 0));
            return exc;
        }

        void load(FunctionDatabase& fdb)
        {
            fdb.add("", &_doStuff);  // just for the alignment
            fdb.add("add", &_add);
        }
    }
}
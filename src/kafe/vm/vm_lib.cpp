#include "vm_lib.hpp"

namespace kafe
{
    namespace StdLibVM
    {
        Value _add(const Value& a, const Value& b)
        {
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
                    for (std::size_t i = 0; i < a.getRef<list_t>().size(); ++i)
                        c.getRef<list_t>().push_back(a.getRef<list_t>()[i]);
                    for (std::size_t i = 0; i < b.getRef<list_t>().size(); ++i)
                        c.getRef<list_t>().push_back(b.getRef<list_t>()[i]);
                    return c;
                }
                return Exception(Exception::LOGIC, "Can not add two " + convertTypeToString(a.type), 0);
            }
            return Exception(Exception::LOGIC, "Can not add two variables of heterogeneous types", 0);
        }

        void load(FunctionDatabase& fdb)
        {
            fdb.add("add", &_add);
        }
    }
}
#include "value.hpp"
#include "../utils.hpp"

namespace kafe
{

    std::string convertTypeToString(ValueType t)
    {
        if (t == TYPE_INT) return "INT";
        else if (t == TYPE_DOUBLE) return "DOUBLE";
        else if (t == TYPE_BOOL) return "BOOL";
        else if (t == TYPE_STRING) return "STRING";
        else if (t == TYPE_LIST) return "LIST";
        else if (t == TYPE_VAR) return "VAR";
        else if (t == TYPE_STRUCT) return "STRUCT";
        else return "???";
    }

    std::ostream& operator<<(std::ostream& os, const Value& v)
    {
        switch(v.type)
        {
        case TYPE_INT:
            os << abc::str(v.get<long>());
            break;

        case TYPE_DOUBLE:
            os << abc::str(v.get<double>());
            break;

        case TYPE_BOOL:
            os << abc::str(v.get<bool>());
            break;

        case TYPE_STRING:
        case TYPE_VAR:
            os << v.get<std::string>();
            break;

        case TYPE_LIST:
        {
            for (std::size_t i=0; i < v.get<Value::list_t>().size(); ++i)
            {
                os << v.get<Value::list_t>()[i] << " ";
            }
            break;
        }

        case TYPE_STRUCT:
            os << v.get<Structure>();
            break;

        default:
            os << "`Unknown value`";
            break;
        }
        return os;
    }

    bool operator!=(const Value& a, const Value& b) { return !(a == b); }
    bool operator>=(const Value& a, const Value& b) { return !(a < b); }
    bool operator<=(const Value& a, const Value& b) { return (a < b) || (a == b); }
    bool operator>(const Value& a, const Value& b) { return (!(a == b)) && (!(a < b)); }

    std::ostream& operator<<(std::ostream& os, const Structure& st)
    {
        os << "Struct id [" << st.struct_id << "]" << std::endl;
        for (auto m : st.members)
        {
            os << "\t" << m.name << " [" << convertTypeToString(m.val.type) << "]" << m.val << std::endl;
        }
        return os;
    }

}  // namespace kafe

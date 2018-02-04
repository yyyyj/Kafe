#include "value.hpp"
#include "../utils.hpp"

namespace kafe
{

    std::string convertTypeToString(ValueType t)
    {
        if (t == ValueType::Int)         return "INT";
        else if (t == ValueType::Double) return "DOUBLE";
        else if (t == ValueType::Bool)   return "BOOL";
        else if (t == ValueType::String) return "STRING";
        else if (t == ValueType::List)   return "LIST";
        else if (t == ValueType::Var)    return "VAR";
        else if (t == ValueType::Struct) return "STRUCT";
        else if (t == ValueType::Addr)   return "ADDR";
        else                             return "???";
    }

    // Structure
    uint8B_t Structure::ID = 0;

    void Structure::add(std::string name, Value val)
    {
        StructElem se = {/* name */ name, /* val */ val};
        members.push_back(se);
    }

    void Structure::set(const std::string& name, Value val)
    {
        StructElem* pse = findMember(name);
        if (pse != nullptr)
            { pse->val = val; }
        else
            { add(name, val); }
    }

    StructElem* Structure::findMember(const std::string& name)
    {
        for (std::size_t i=0; i < members.size(); ++i)
        {
            if (members[i].name == name)
                { return &members[i]; }
        }
        return nullptr;
    }

    // Value
    template <> ValueType Value::guessType<int8B_t>()       { return ValueType::Int; }
    template <> ValueType Value::guessType<double>()        { return ValueType::Double; }
    template <> ValueType Value::guessType<bool>()          { return ValueType::Bool; }
    template <> ValueType Value::guessType<std::string>()   { return ValueType::String; }
    template <> ValueType Value::guessType<Value::list_t>() { return ValueType::List; }
    template <> ValueType Value::guessType<Structure>()     { return ValueType::Struct; }
    // small trick related to the problem with mpark::variant already using a size_t
    template <> ValueType Value::guessType<std::size_t>()   { return ValueType::Addr; }
    template <typename T> ValueType Value::guessType()      { return ValueType::Unknown; }

    std::ostream& operator<<(std::ostream& os, const Value& v)
    {
        switch(v.type)
        {
        case ValueType::Int:
            os << abc::str(v.get<int8B_t>());
            break;

        case ValueType::Double:
            os << abc::str(v.get<double>());
            break;

        case ValueType::Bool:
            os << abc::str(v.get<bool>());
            break;

        case ValueType::String:
        case ValueType::Var:
            os << v.get<std::string>();
            break;

        case ValueType::List:
        {
            for (std::size_t i=0; i < v.get<Value::list_t>().size(); ++i)
            {
                os << v.get<Value::list_t>()[i] << " ";
            }
            break;
        }

        case ValueType::Struct:
            os << v.get<Structure>();
            break;

        case ValueType::Addr:
            os << abc::hexstr(v.get<addr_t>());
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
    bool operator> (const Value& a, const Value& b) { return (!(a == b)) && (!(a < b)); }

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

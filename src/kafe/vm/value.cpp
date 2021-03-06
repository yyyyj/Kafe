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

#include <kafe/vm/value.hpp>
#include <kafe/utils.hpp>

namespace kafe
{

    using namespace abc;

    std::string convertTypeToString(ValueType t)
    {
        if (t == ValueType::Int)            return "INT";
        else if (t == ValueType::Double)    return "DOUBLE";
        else if (t == ValueType::Bool)      return "BOOL";
        else if (t == ValueType::String)    return "STRING";
        else if (t == ValueType::List)      return "LIST";
        else if (t == ValueType::Var)       return "VAR";
        else if (t == ValueType::Struct)    return "STRUCT";
        else if (t == ValueType::Addr)      return "ADDR";
        else if (t == ValueType::Exception) return "EXCEPTION";
        else if (t == ValueType::Empty)     return "EMPTY";
        else                                return "UNKNOWN";
    }

    // Structure
    int_t Structure::ID = 0;

    void Structure::add(std::string name, Value val)
    {
        StructElem se = {/* name */ name, /* val */ val};
        members.push_back(se);
    }

    void Structure::set(const std::string& name, Value val)
    {
        StructElem* pse = findMember(name);
        if (pse != nullptr)
            pse->val = val;
        else
            add(name, val);
    }

    abc::StructElem* Structure::findMember(const std::string& name)
    {
        for (std::size_t i=0; i < members.size(); ++i)
        {
            if (members[i].name == name)
                return &members[i];
        }
        return nullptr;
    }

    bool Structure::hasParent(const Structure& other)
    {
        return std::find(struct_id.begin(), struct_id.end(), other.struct_id[other.struct_id.size() - 1]) != struct_id.end();
    }

    // Value
    template <> ValueType Value::guessType<int_t>()     { return ValueType::Int; }
    template <> ValueType Value::guessType<double>()    { return ValueType::Double; }
    template <> ValueType Value::guessType<bool>()      { return ValueType::Bool; }
    template <> ValueType Value::guessType<str_t>()     { return ValueType::String; }
    template <> ValueType Value::guessType<list_t>()    { return ValueType::List; }
    template <> ValueType Value::guessType<Structure>() { return ValueType::Struct; }
    template <> ValueType Value::guessType<Exception>() { return ValueType::Exception; }
    template <> ValueType Value::guessType<addr_t>()    { return ValueType::Addr; }
    template <typename T> ValueType Value::guessType()  { return ValueType::Unknown; }

    std::ostream& operator<<(std::ostream& os, const Value& v)
    {
        switch(v.type)
        {
        case ValueType::Int:
            os << abc::str(v.get<int_t>());
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
            for (std::size_t i=0; i < v.get<list_t>().size(); ++i)
                os << v.get<list_t>()[i] << " ";
            break;
        }

        case ValueType::Struct:
            os << v.get<Structure>();
            break;

        case ValueType::Addr:
            os << abc::hexstr(v.get<addr_t>());
            break;

        case ValueType::Exception:
            os << v.get<abc::Exception>();
            break;

        case ValueType::Empty:
            os << "***";
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
        os << "Struct id [" << st.struct_id[st.struct_id.size() - 1] << "]" << std::endl;
        for (auto m : st.members)
            os << "\t" << m.name << " [" << convertTypeToString(m.val.type) << "]" << m.val << std::endl;
        return os;
    }

}  // namespace kafe

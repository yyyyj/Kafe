#ifndef kafe_value
#define kafe_value

#include <map>
#include <string>
#include <vector>
#include <cstdint>
#include <exception>
#include <stdexcept>

#include "../types.hpp"
#include "../libs/variant.hpp"

namespace kafe
{

    // all the data types defined for kafe are listed below
    enum class ValueType
    {
        Int     = 1 << 0,
        Double  = 1 << 1,
        Bool    = 1 << 2,
        String  = 1 << 3,
        List    = 1 << 4,
        Var     = 1 << 5,
        Struct  = 1 << 6,
        Addr    = 1 << 7,

        Unknown = -1
    };

    std::string convertTypeToString(ValueType t);

    // forward declaration for Structure
    struct StructElem;
    struct Value;

    struct Structure
    {
        static uint8B_t ID;

        // name of the variable : default value
        std::vector<StructElem> members;
        // in order to be able to identify a structure
        // each structure has the same struct_id as its base structure
        uint8B_t struct_id;

        Structure() :
            struct_id(Structure::ID++)
        {}

        Structure(const Structure& other) :
            members(other.members)
            , struct_id(other.struct_id)
        {}

        void add(std::string name, Value val);
        void set(const std::string& name, Value val);
        StructElem* findMember(const std::string& name);

        bool operator==(const Structure& other) const
        {
            return (other.struct_id == struct_id);
        }
    };

    // a data holder for kafe values
    struct Value
    {
        typedef std::vector<Value> list_t;

        ValueType type;
        mpark::variant<int8B_t, double, bool, std::string, list_t, Structure, addr_t> value;

        Value()                                                       {}
        Value(ValueType t)                       : type(t)            {}
        Value(ValueType t, int8B_t i)            : type(t)            { mpark::get<int8B_t>(value) = i; }
        Value(ValueType t, double d)             : type(t)            { mpark::get<double>(value) = d; }
        Value(ValueType t, bool b)               : type(t), value(b)  {}
        Value(ValueType t, const std::string& s) : type(t), value(s)  {}
        Value(ValueType t, list_t l)             : type(t), value(l)  {}
        Value(ValueType t, Structure st)         : type(t), value(st) {}
        Value(ValueType t, addr_t u)             : type(t)            { mpark::get<addr_t>(value) = u; }

        template <typename T> T    get() const { return mpark::get<T>(value); }
        template <typename T> T&   getRef()    { return mpark::get<T>(value); }
        template <typename T> void set(T val)  { mpark::get<T>(value) = val; }

        bool operator==(const Value& other) const
        {
            return (other.type == type) && (other.value == value);
        }

        bool operator<(const Value& other) const
        {
            return (other.type == type) &&
                   ((other.type == ValueType::Int)    ? (other.get<int8B_t>() >= get<int8B_t>())                       : true) &&
                   ((other.type == ValueType::Double) ? (other.get<double>() >= get<double>())                         : true) &&
                   ((other.type == ValueType::Bool)   ? (other.get<bool>() == true && get<bool>() == false)            : true) &&
                   ((other.type == ValueType::String) ? (other.get<std::string>().size() >= get<std::string>().size()) : true) &&
                   ((other.type == ValueType::List)   ? (other.get<list_t>().size() >= get<list_t>().size())           : true) &&
                   ((other.type == ValueType::Var)    ? (other.get<std::string>().size() >= get<std::string>().size()) : true) &&
                   // we can not compare structures nor addresses
                   ((other.type == ValueType::Struct) ? false : true) &&
                   ((other.type == ValueType::Addr)   ? false : true);
        }

        template <typename T>
        static ValueType guessType();
    };

    std::ostream& operator<<(std::ostream& os, const Value& v);

    bool operator!=(const Value& a, const Value& b);
    bool operator>=(const Value& a, const Value& b);
    bool operator<=(const Value& a, const Value& b);
    bool operator> (const Value& a, const Value& b);

    // custom type to create stacks and avoid to much verbosity
    typedef std::vector<Value> ValueStack_t;

    struct StructElem
    {
        std::string name;
        Value val;
    };

    std::ostream& operator<<(std::ostream& os, const Structure& st);

    struct Call
    {
        // we'll do something like a RLE to be able top optimize things like
        // [context = main() =>] function() => function() => function() => ...
        struct Pair
        {
            std::size_t cnt;
            addr_t pos;
        };

        std::string segmentName;
        // all the positions from where the segment was called
        // in order to be able to go back
        std::vector<Pair> lastPositions;
        // internal variables stack
        std::map<std::string, Value> vars;
    };

}  // namespace kafe

#endif // kafe_value

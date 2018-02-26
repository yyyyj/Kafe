#ifndef kafe_value
#define kafe_value

#include <string>
#include <vector>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <unordered_map>
#include <variant>
#include <utility>

#include "../types.hpp"
#include "../exc.hpp"

namespace kafe
{
    // all the data types defined for kafe are listed below
    enum class ValueType
    {
        Int       = 1 << 0,
        Double    = 1 << 1,
        Bool      = 1 << 2,
        String    = 1 << 3,
        List      = 1 << 4,
        Var       = 1 << 5,
        Struct    = 1 << 6,
        Addr      = 1 << 7,
        Exception = 1 << 8,

        Unknown = -1
    };

    std::string convertTypeToString(ValueType t);

    // forward declaration for Structure
    struct StructElem;
    struct Value;

    struct Structure
    {
        static uint_t ID;

        // name of the variable : default value
        std::vector<StructElem> members;
        // in order to be able to identify a structure
        // each structure has the same struct_id as its base structure
        uint_t struct_id;

        Structure() : struct_id(Structure::ID++) {}
        Structure(const Structure& other) : members(other.members), struct_id(other.struct_id) {}

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
        std::variant<int_t, double, bool, str_t, list_t, Structure, addr_t, Exception> value;
        bool is_const;

        Value() : is_const(false)                      {}
        Value(ValueType t) : type(t), is_const(false)  {}
        Value(ValueType t, bool b) : type(t), value(b), is_const(false) {}

        Value& operator=(Value& other)
        {
            if (this != &other)
            {
                type = other.type;
                value = other.value;
                is_const = other.is_const;
            }
            return *this;
        }

        template <typename T> T  get() const { return std::get<T>(value); }
        template <typename T> T& getRef()
        {
            if (!std::holds_alternative<T>(value))
                set<T>({});
            return std::get<T>(value);
        }
        template <typename T> void set(T&& val) { value = std::move(val); }
        template <typename T> void set(const T& val) { value = T(val); }

        bool operator==(const Value& other) const
        {
            return (other.type == type) && (other.value == value);
        }

        bool operator<(const Value& other) const
        {
            return (other.type == type) &&
                   ((other.type == ValueType::Int)    ? (other.get<int_t>() >= get<int_t>())                 : true) &&
                   ((other.type == ValueType::Double) ? (other.get<double>() >= get<double>())               : true) &&
                   ((other.type == ValueType::Bool)   ? (other.get<bool>() == true && get<bool>() == false)  : true) &&
                   ((other.type == ValueType::String) ? (other.get<str_t>().size() >= get<str_t>().size())   : true) &&
                   ((other.type == ValueType::List)   ? (other.get<list_t>().size() >= get<list_t>().size()) : true) &&
                   ((other.type == ValueType::Var)    ? (other.get<str_t>().size() >= get<str_t>().size())   : true) &&
                   // we can not compare structures nor addresses nor exceptions
                   ((other.type == ValueType::Struct) ?    false : true) &&
                   ((other.type == ValueType::Addr)   ?    false : true) &&
                   ((other.type == ValueType::Exception) ? false : true);
        }

        template <typename T>
        static ValueType guessType();
    };

    std::ostream& operator<<(std::ostream& os, const Value& v);

    bool operator!=(const Value& a, const Value& b);
    bool operator>=(const Value& a, const Value& b);
    bool operator<=(const Value& a, const Value& b);
    bool operator> (const Value& a, const Value& b);

    // custom types to create stacks and avoid to much verbosity
    typedef Value::list_t list_t;
    typedef std::vector<Value> ValueStack_t;
    typedef std::unordered_map<std::string, Value> VarStack_t;
    struct Call
    {
        addr_t lastPos;
        addr_t lastStackSize;
        VarStack_t vars;
        std::vector<str_t> refs_to_gscope;
    };
    typedef std::vector<Call> CallStack_t;
    typedef std::unordered_map<std::string, Structure> StructureMap_t;

    struct StructElem
    {
        std::string name;
        Value val;
    };

    std::ostream& operator<<(std::ostream& os, const Structure& st);

}  // namespace kafe

#endif // kafe_value

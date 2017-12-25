#ifndef kafe_value
#define kafe_value

#include <map>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

namespace kafe
{

    // all the data types defined for kafe are listed below
    // they probably won't change now (dec. 18 2017)
    enum ValueType
    {
        TYPE_INT         = 1 << 0,
        TYPE_DOUBLE      = 1 << 1,
        TYPE_BOOL        = 1 << 2,
        TYPE_STRING      = 1 << 3,
        TYPE_LIST        = 1 << 4,
        TYPE_VAR         = 1 << 5,
        TYPE_STRUCT      = 1 << 6,
    };

    // forward declaration for Structure
    struct StructElem;

    struct Structure
    {
        // name of the variable : default value
        std::vector<StructElem> members;
        // in order to be able to identify a structure
        // each structure has the same struct_id as its base structure
        int struct_id;

        Structure() {}

        Structure(const Structure& other)
        {
            members = other.members;
            struct_id = other.struct_id;
        }

        bool operator==(const Structure& other) const
        {
            return (other.struct_id == struct_id);
        }
    };

    // a data holder for kafe values
    struct Value
    {
        ValueType type;

        long intValue;
        double doubleValue;
        bool boolValue;
        std::string stringValue;
        std::vector<Value> listValue;

        Structure structValue;

        Value() {}
        Value(ValueType t, long i)   : type(t), intValue(i)    {}
        Value(ValueType t, double d) : type(t), doubleValue(d) {}
        Value(ValueType t, bool b)   : type(t), boolValue(b)   {}
        Value(ValueType t, const std::string& s) : type(t), stringValue(s) {}
        Value(ValueType t, std::vector<Value> l) : type(t), listValue(l)   {}
        Value(ValueType t, Structure st) : type(t), structValue(st) {}


        bool operator==(const Value& other) const
        {
            return (other.type == type) &&
                   ((other.type == TYPE_INT) ? (other.intValue == intValue) : true) &&
                   ((other.type == TYPE_DOUBLE) ? (other.doubleValue == doubleValue) : true) &&
                   ((other.type == TYPE_BOOL) ? (other.boolValue == boolValue) : true) &&
                   ((other.type == TYPE_STRING) ? (other.stringValue == stringValue) : true) &&
                   ((other.type == TYPE_LIST) ? (other.listValue == listValue) : true) &&
                   ((other.type == TYPE_VAR) ? (other.stringValue == stringValue) : true) &&
                   ((other.type == TYPE_STRUCT) ? (other.structValue == structValue) : true);
        }

        bool operator<(const Value& other) const
        {
            return (other.type == type) &&
                   ((other.type == TYPE_INT) ? (other.intValue >= intValue) : true) &&
                   ((other.type == TYPE_DOUBLE) ? (other.doubleValue >= doubleValue) : true) &&
                   ((other.type == TYPE_BOOL) ? (other.boolValue == true && boolValue == false) : true) &&
                   ((other.type == TYPE_STRING) ? (other.stringValue.size() >= stringValue.size()) : true) &&
                   ((other.type == TYPE_LIST) ? (other.listValue.size() >= listValue.size()) : true) &&
                   ((other.type == TYPE_VAR) ? (other.stringValue.size() >= stringValue.size()) : true) &&
                   ((other.type == TYPE_STRUCT) ? false : false);
        }
    };

    bool operator!=(const Value& a, const Value& b);
    bool operator>=(const Value& a, const Value& b);
    bool operator<=(const Value& a, const Value& b);
    bool operator>(const Value& a, const Value& b);

    // custom type to create stacks and avoid to much verbosity
    typedef std::vector<Value> ValueStack_t;

    struct StructElem
    {
        std::string name;
        Value val;
    };

    struct Call
    {
        // we'll do something like a RLE to be able top optimize things like
        // [context = main() =>] function() => function() => function() => ...
        struct Pair
        {
            std::size_t cnt;
            std::size_t pos;
        };

        std::string segmentName;
        // all the positions from where the segment was called
        // in order to be able to go back
        std::vector<Pair> lastPositions;
    };

}  // namespace kafe

#endif // kafe_value

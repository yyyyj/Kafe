#ifndef kafe_value
#define kafe_value

#include <map>
#include <string>
#include <vector>

namespace kafe
{

    enum ValueType
    {
        TYPE_INT    = 1 << 0,
        TYPE_DOUBLE = 1 << 1,
        TYPE_BOOL   = 1 << 2,
        TYPE_STRING = 1 << 3,
        TYPE_LIST   = 1 << 4,
        TYPE_VAR    = 1 << 5,
        TYPE_STRUCT = 1 << 6,
    };

    struct Value;

    // name of the variable : default value
    using Structure = std::vector<StructElem>;

    struct StructElem
    {
        std::string name;
        Value val;
    };

    struct Value
    {
        ValueType type;

        int intValue;
        double doubleValue;
        bool boolValue;
        std::string stringValue;
        std::vector<Value> listValue;
        Structure structValue;
    };

    struct Call
    {
        std::string segmentName;
        std::vector<int> lastPosition;
    };

}  // namespace kafe

#endif // kafe_value

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
        TYPE_BOOL   = 1 << 1,
        TYPE_STRING = 1 << 2,
        TYPE_LIST   = 1 << 3,
        TYPE_STRUCT = 1 << 4,
    };

    struct Value;

    // name of the variable : default value
    using Structure = std::map<std::string, Value>;

    struct Value
    {
        ValueType type;

        int intValue;
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

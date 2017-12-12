#ifndef kafe_value
#define kafe_value

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
    };

    struct Value
    {
        ValueType type;

        int intValue;
        bool boolValue;
        std::string stringValue;
        std::vector<Value> listValue;
    };

    struct Call
    {
        std::string segmentName;
        std::vector<int> lastPosition;
    };

    struct Structure
    {
        std::map<std::string, Value> elements;
    };

}  // namespace kafe

#endif // kafe_value

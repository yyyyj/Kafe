#ifndef vm_value
#define vm_value

#include <string>
#include <vector>

namespace vm
{

    enum ValueType
    {
        TYPE_INT    = 1 << 0,
        TYPE_BOOL   = 1 << 1,
        TYPE_STRING = 1 << 2,
    };

    struct Value
    {
        ValueType type;
        int intValue;
        bool boolValue;
        std::string stringValue;
    };

    struct Call
    {
        std::string segmentName;
        std::vector<int> lastPosition;
    };

}  // namespace vm

#endif // vm_value

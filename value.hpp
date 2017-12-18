#ifndef kafe_value
#define kafe_value

#include <map>
#include <string>
#include <vector>

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
        TYPE_STRUCT_DECL = 1 << 7,
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
    };

    // a data holder for kafe values
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
    // custom type to create stacks and avoid to much verbosity
    typedef std::vector<Value> ValueStack_t;

    struct StructElem
    {
        std::string name;
        Value val;
    };

    struct Call
    {
        std::string segmentName;
        // all the positions from where the segment was called
        // in order to be able to go back
        // TODO : possible memory error if using a recursive segment
        std::vector<int> lastPosition;
    };

}  // namespace kafe

#endif // kafe_value

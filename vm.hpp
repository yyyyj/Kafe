#ifndef kafe_vm
#define kafe_vm

#include "instructions.hpp"
#include "value.hpp"
#include "utils.hpp"

#include <map>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

namespace kafe
{

    class VM
    {
    private:
        int m_stack_size;
        std::vector<Value> m_stack;
        // variable name => Value
        std::map<std::string, Value> m_variables;
        // just keeping the position of the segments
        std::map<std::string, unsigned> m_segments;
        // keeping track of the segments' calls
        std::vector<Call> m_call_stack;
        // keeping the signatures of the declared structures
        // name of the struct : object Structure (.elements => name of the var : default value)
        std::map<std::string, Structure> m_struct_definitions;

        bool m_debug;

        void push(Value value);
        Value pop();
        void clear();

        char getByte(char* bytecode, unsigned s, unsigned i);
        int getXBytesInt(char* bytecode, unsigned s, unsigned& i, unsigned X=2);
        std::string readString(char* bytecode, unsigned s, unsigned& i, unsigned strSize);

        std::string getSegmentName(char* bytecode, unsigned s, unsigned& i);
        void goToSegmentPosition(const std::string& segmentName, unsigned& i);
        void pushCallStack(const std::string& segmentName, unsigned lastPos);
        bool canValueCompareTo(Value val, bool c=true);

        void builtins(char instruction);

    public:
        VM();
        ~VM();

        int exec(char* bytecode, unsigned s);
        // int execSegment(char* bytecode, char* segment_name);
        void setDebug(bool debug);

        std::vector<Value>& getStack();
    };

}  // namespace kafe

#endif // kafe_vm

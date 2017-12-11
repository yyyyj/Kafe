#ifndef vm_vm
#define vm_vm

#include "instructions.hpp"
#include "value.hpp"
#include "utils.hpp"

#include <map>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

namespace vm
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

}  // namespace vm

#endif // vm_vm

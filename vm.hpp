#ifndef kafe_vm
#define kafe_vm

#include "instructions.hpp"
#include "bytecode.hpp"
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
        // instruction pointer
        std::size_t m_ip;
        ValueStack_t m_stack;
        // variable name => Value
        std::map<std::string, Value> m_variables;
        // just keeping the position of the segments
        std::map<std::string, std::size_t> m_segments;
        // keeping track of the segments' calls
        std::vector<Call> m_call_stack;
        // keeping the signatures of the declared structures
        // name of the struct : object Structure (.elements => name of the var : default value)
        std::map<std::string, Structure> m_struct_definitions;

        bool m_debug;

        void push(Value value);
        Value pop();
        void clear();

        bcval_t getByte(bytecode_t& bytecode, std::size_t i);
        int getXBytesInt(bytecode_t& bytecode, unsigned bytesCount=2);
        std::string readString(bytecode_t& bytecode, std::size_t strSize);

        std::string getSegmentName(bytecode_t& bytecode);
        void goToSegmentPosition(const std::string& segmentName);
        void pushCallStack(const std::string& segmentName, std::size_t lastPos);
        bool canValueCompareTo(Value val, bool c=true);

        void builtins(bcval_t instruction);

    public:
        VM();
        ~VM();

        int exec(bytecode_t bytecode);
        // int execSegment(char* bytecode, char* segment_name);
        void setDebug(bool debug);

        ValueStack_t& getStack();
    };

}  // namespace kafe

#endif // kafe_vm

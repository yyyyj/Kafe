#ifndef kafe_vm
#define kafe_vm

#include "instructions.hpp"
#include "../types.hpp"
#include "../utils.hpp"
#include "value.hpp"

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>

#define EXP_DOUBLE_LIMIT 0b100110100

namespace kafe
{

    class VM
    {
    private:
        std::size_t m_stack_size;
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

        bytecode_t m_loaded_bytecode;
        bool m_has_loaded_bytecode;

        int m_debug_mode;
        bool m_debug;

        void push(Value value);
        Value pop();
        void clear();

        inst_t getByte(bytecode_t& bytecode, std::size_t i);
        long long getXBytesInt(bytecode_t& bytecode, unsigned bytesCount=2);
        int get2BytesInt(bytecode_t& bytecode);
        long get4BytesInt(bytecode_t& bytecode);
        double readDouble(bytecode_t& byteocde);
        std::string readString(bytecode_t& bytecode, std::size_t strSize);
        bool readBool(bytecode_t& bytecode);

        std::size_t getSegmentAddr(const std::string& segmentName);
        std::string getSegmentName(bytecode_t& bytecode);
        void goToSegmentPosition(const std::string& segmentName);
        void pushCallStack(const std::string& segmentName, std::size_t lastPos);
        std::string performJump(bytecode_t& bytecode);
        void retFromSegment(bytecode_t& bytecode);

        void builtins(bytecode_t& bytecode);

    public:
        VM();
        ~VM();

        // the debug flags for the VM
        static const int FLAG_BASIC_DEBUG = 1 << 0;

        bytecode_t readFile(const std::string& filePath);

        int execFromFile(const std::string& filePath);
        int exec(bytecode_t bytecode);
        void setMode(int mode);
        void load(bytecode_t bytecode);
        int exec();
        void callSegment(const std::string& seg_name);

        template <typename T> void push(T value)
        {
            ValueType t = Value::guessType<T>();
            if (t == ValueType::Unknown)
                { throw std::runtime_error("Can not guess value type when trying to push a value on the stack"); }
            Value c(t, value);
            push(c);
        }

        ValueStack_t& getStack();
        void saveBytecode(const std::string& filename);
    };

}  // namespace kafe

#endif // kafe_vm

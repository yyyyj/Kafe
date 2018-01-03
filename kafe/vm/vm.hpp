#ifndef kafe_vm
#define kafe_vm

#include "instructions.hpp"
#include "../types.hpp"
#include "../utils.hpp"
#include "value.hpp"
#include "optimizer/optimizer.hpp"
#include "../libs/functionsDB.hpp"

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>

#define EXP_DOUBLE_LIMIT 0b100110100  // = 308 (exponent limit for doubles)

namespace kafe
{

    class VM
    {
    private:
        bytecode_t m_bytecode;
        bool m_has_loaded_bytecode;
        Optimizer::Main m_optimizer;
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
        FunctionsDatabase m_fun_db;

        int m_debug_modes;
        bool m_debug;

        void push(Value value);
        Value pop();
        void clear();

        inst_t readByte(bytecode_t& bytecode, std::size_t i);
        unsigned long long readXBytesInt(bytecode_t& bytecode, unsigned bytesCount);
        int readInt(bytecode_t& bytecode);
        long readLong(bytecode_t& bytecode);
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

        void startOptimizer();

    public:
        VM();
        VM(bytecode_t bytecode);
        ~VM();

        // the debug flags for the VM
        static const int FLAG_BASIC_DEBUG = 1 << 0;
        static const int FLAG_SAVE_OPTIMIZED_BYTECODE = 1 << 1;

        bytecode_t readFile(const std::string& filePath);
        int loadFromFile(const std::string& filePath);
        void load(bytecode_t bytecode);
        int exec();
        void callSegment(const std::string& seg_name);

        void setMode(int mode);

        template <typename T> void push(T value)
        {
            ValueType t = Value::guessType<T>();
            if (t == ValueType::Unknown)
                { throw std::runtime_error("Can not guess value type when trying to push a value on the stack"); }
            Value c(t, value);
            push(c);
        }

        ValueStack_t& getStack();
    };

}  // namespace kafe

#endif // kafe_vm

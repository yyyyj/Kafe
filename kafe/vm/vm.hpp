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

#define EXP_DOUBLE_LIMIT 0b0100110100
#define EXP_DOUBLE_SIGN  0b1000000000

namespace kafe
{

    class VM
    {
    private:
        addr_t m_stack_size;
        addr_t m_ip;
        ValueStack_t m_stack;
        // variable name => Value
        std::map<std::string, Value> m_variables;
        // just keeping the position of the segments
        std::map<std::string, addr_t> m_segments;
        // keeping track of the segments' calls
        std::vector<Call> m_call_stack;
        // keeping the signatures of the declared structures
        // name of the struct : object Structure (.elements => name of the var : default value)
        std::map<std::string, Structure> m_struct_definitions;
        // keeping the loaded bytecode into the VM to use easily without passing it around
        bytecode_t m_bytecode;
        int m_debug_mode;

        void  push(Value value);
        Value pop();
        void  clear();
        bool  findVar(const std::string& varName);
        Value getVar(const std::string& varName);
        // about types
        inst_t      readByte     (addr_t i);
        uint8B_t    readXBytesInt(unsigned char bytesCount=2);
        int2B_t     read2BytesInt();
        int4B_t     read4BytesInt();
        int8B_t     read8BytesInt();
        double      readDouble   ();
        std::string readString   ();
        bool        readBool     ();
        // about segments and jumps
        addr_t      getSegmentAddr     (const std::string& segmentName);
        void        goToSegmentPosition(const std::string& segmentName);
        void        pushCallStack      (const std::string& segmentName, addr_t lastPos);
        std::string performJump        ();
        void        retFromSegment     ();

        void exec_handleDataTypesDecl(inst_t instruction);
        void exec_handleStructures   (inst_t instruction);
        void exec_handleSegments     (inst_t instruction);
        void exec_handleBuiltins     ();

    public:
        VM();
        ~VM();

        // the debug flags for the VM
        static const int FLAG_BASIC_DEBUG = 1 << 0;
        static const int FLAG_INTERACTIVE = 1 << 1;

        bytecode_t readFile(const std::string& filePath);

        int  execFromFile(const std::string& filePath);
        int  exec        (bytecode_t bytecode);
        void setMode     (int mode);
        void load        (bytecode_t bytecode);
        int  exec        ();
        int  callSegment (const std::string& seg_name);

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

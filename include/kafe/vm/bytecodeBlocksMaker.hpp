/*
* Kafe - A programming language running on a VM
*
* Copyright (c) 2018 SuperFola and the Kafe open source project
* Licensed under MPL-2.0
*
* This notice may not be removed or altered from any source ditribution
*
* See https://superfola.github.io/Kafe/CONTRIBUTORS.txt for the list of Kafe project authors
* See https://superfola.github.io/Kafe/LICENSE for license information
*/

#ifndef kafe_vm_bytecodeblocksmaker
#define kafe_vm_bytecodeblocksmaker

#include <vector>
#include <variant>
#include <functional>
#include <unordered_map>

#include <kafe/types.hpp>
#include <kafe/utils.hpp>
#include <kafe/KafeException.hpp>

namespace kafe
{
    namespace abc
    {

        // forward declaration
        class VM;

        constexpr int EXP_DOUBLE_LIMIT = 0b0100110100;  // (308) exponent limit for a double
        constexpr int EXP_DOUBLE_SIGN = 0b1000000000;   // (512)

        struct Block
        {
            std::variant<uint_t, micro_int_t, smol_int_t, int_t, double, str_t, bool> val;

            template <typename T> bool holds() { return std::holds_alternative<T>(val); }
            template <typename T> T    get() { return std::get<T>(val); }
            template <typename T> void set(T&& v) { val = std::forward(v); }
        };
        
        class BytecodeBlocksMaker
        {
        private:
            addr_t& m_ip;
            bytecode_t& m_bytecode;
            std::size_t m_size;
            bool m_typecheck;
            // mapping instruction pointer to object
            std::unordered_map<addr_t, Block> m_objects;

            typedef void(VM::*FNRAISE)(int, const std::string&);
            //typedef std::function<void(int, const std::string&)> FNRAISE;
            FNRAISE raiseException;

        public:
            BytecodeBlocksMaker(addr_t&, bytecode_t&);
            ~BytecodeBlocksMaker();

            void setup(FNRAISE);
            void setTypeCheck(bool);

            // about types
            inst_t      readByte     (addr_t i);
            uint_t      readXBytesInt(unsigned char bytesCount = 2);
            micro_int_t read2BytesInt();
            smol_int_t  read4BytesInt();
            int_t       read8BytesInt();
            double      readDouble   ();
            str_t       readString   ();
            bool        readBool     ();
            
            void clear();
        };

    }  // namespace abc
}  // namespace kafe

#endif  // kafe_vm_bytecodeblocksmaker
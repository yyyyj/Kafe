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

#ifndef kafe_vm_bytecode
#define kafe_vm_bytecode

#include <vector>

#include <kafe/types.hpp>

namespace kafe
{
    namespace abc
    {
        
        struct Byte
        {
            bool read;
            inst_t code;
        };
        
        class Bytecode
        {
        private:
            std::vector<Byte> m_bytecode;
            bytecode_t m_raw_bytecode;
        
        public:
            Bytecode();
            Bytecode(const bytecode_t&);
            ~Bytecode();
            
            void load(const bytecode_t&);
            
            std::size_t size() const;
            void clear();
            inst_t& operator[](std::size_t index);
            Byte& at(std::size_t index);
            bytecode_t& get();
        };
        
    }  // namespace abc
}  // namespace kafe

#endif  // kafe_vm_bytecode
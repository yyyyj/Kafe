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

#include <kafe/vm/bytecode.hpp>

namespace kafe
{
    namespace abc
    {

        Bytecode::Bytecode() {}
        
        Bytecode::Bytecode(const bytecode_t& bytecode) : m_raw_bytecode(bytecode)
        {
            load(bytecode);
        }
        
        Bytecode::~Bytecode()
        {
            clear();
        }
        
        void Bytecode::load(const bytecode_t& bytecode)
        {
            if (m_bytecode.size() != 0)
                clear();
            m_raw_bytecode = bytecode;
            
            for (std::size_t i = 0; i < bytecode.size(); ++i)
            {
                Byte b = {/* read = */ false, /* code = */ bytecode[i], /* size = */ 0, /* evaluated = */ Value()};
                m_bytecode.push_back(b);
            }
        }

        std::size_t Bytecode::size() const
        {
            return m_bytecode.size();
        }
        
        void Bytecode::clear()
        {
            m_bytecode.clear();
        }

        inst_t& Bytecode::operator[](std::size_t index)
        {
            return m_bytecode[index].code;
        }

        Byte& Bytecode::at(std::size_t index)
        {
            return m_bytecode[index];
        }

        bytecode_t& Bytecode::get()
        {
            return m_raw_bytecode;
        }
        
    }  // namespace abc
}  // namespace kafe
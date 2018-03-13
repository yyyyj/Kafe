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

#include <kafe/vm/bytecodeBlocksMaker.hpp>
#include <kafe/vm/vm.hpp>

namespace kafe
{
    namespace abc
    {

        BytecodeBlocksMaker::BytecodeBlocksMaker(addr_t& ip, Bytecode& bytecode, ErrorHandler& errh) : m_ip(ip), m_bytecode(bytecode), m_errh(errh), m_typecheck(false)
        {
            m_objects.reserve(24);
        }

        BytecodeBlocksMaker::~BytecodeBlocksMaker()
        {
            clear();
        }

        void BytecodeBlocksMaker::raiseException(int error, const std::string& msg)
        {
            m_errh.raiseException(error, msg, m_ip);
        }

        void BytecodeBlocksMaker::setTypeCheck(bool typecheck)
        {
            m_typecheck = typecheck;
        }

        inst_t BytecodeBlocksMaker::readByte(addr_t i)
        {
            if (i < m_bytecode.size())
                return m_bytecode[i];
            raiseException(Exception::CRITIC, "Index out of range, can not get next byte");
        }

        uint_t BytecodeBlocksMaker::readXBytesInt(unsigned char bytesCount)
        {
            uint_t v = readByte(++m_ip);
            for (unsigned char k = 1; k < bytesCount; ++k)
                v = (v << 8) + readByte(++m_ip);
            return v;
        }

        micro_int_t BytecodeBlocksMaker::read2BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;

                Block b;
                b.set<micro_int_t>(abc::setSign((micro_int_t)readXBytesInt(2), /* bytesCount */ 2));
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<micro_int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<micro_int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 2 bytes integer");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<micro_int_t>();
        }

        smol_int_t BytecodeBlocksMaker::read4BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;
                
                Block b;
                b.set<smol_int_t>(abc::setSign((smol_int_t)readXBytesInt(4), /* bytesCount */ 4));
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<smol_int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<smol_int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 4 bytes integer");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<smol_int_t>();
        }

        int_t BytecodeBlocksMaker::read8BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;

                Block b;
                b.set<int_t>(abc::setSign((int_t)readXBytesInt(8), /* bytesCount */ 8));
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 8 bytes integer");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<int_t>();
        }

        double BytecodeBlocksMaker::readDouble()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;

                smol_uint_t int_part = read4BytesInt();
                micro_int_t exp = abc::abs(read2BytesInt());
                exp = (exp > EXP_DOUBLE_LIMIT) ? EXP_DOUBLE_LIMIT : ((exp < -EXP_DOUBLE_LIMIT) ? -EXP_DOUBLE_LIMIT : exp);
                exp *= (exp & EXP_DOUBLE_SIGN) ? (-1) : (+1);

                Block b;
                b.set<double>(double(int_part) * std::pow(10, exp));
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<double>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<double>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a double previously stored");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<double>();
        }

        str_t BytecodeBlocksMaker::readString()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;

                str_t work = "";
                while (true)
                {
                    inst_t byte = readByte(++m_ip);
                    if (byte != 0x00)
                        work += byte;
                    else
                        break;
                }

                Block b;
                b.set<str_t>(std::move(work));
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<str_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<str_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored string");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<str_t>();
        }

        bool BytecodeBlocksMaker::readBool()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(m_ip).read)
            {
                // read and register
                m_bytecode.at(m_ip).read = true;

                Block b;
                b.set<bool>(readByte(++m_ip) > 0);
                b.size = (m_ip - last);
                m_objects[last] = b;

                return b.get<bool>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<bool>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a boolean previously stored");
            }
            m_ip += m_objects[last].size;
            return m_objects[last].get<bool>();
        }

        void BytecodeBlocksMaker::clear()
        {
            m_objects.clear();
        }

    } // namespace abc
}  // namespace kafe
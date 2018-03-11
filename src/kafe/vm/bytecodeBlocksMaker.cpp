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

        BytecodeBlocksMaker::BytecodeBlocksMaker(addr_t& ip, bytecode_t& bytecode) : m_ip(ip), m_bytecode(bytecode), m_size(0), m_typecheck(false)
        {
            m_objects.reserve(24);
        }

        BytecodeBlocksMaker::~BytecodeBlocksMaker()
        {
            clear();
        }

        void BytecodeBlocksMaker::raiseException(int error, const std::string& msg)
        {
            m_errh.raiseException(error, msg);
        }

        void BytecodeBlocksMaker::setup(ErrorHandler* errh)
        {
            m_errh = errh;
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
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                uint_t v = readByte(++m_ip);
                for (unsigned char k = 1; k < bytesCount; ++k)
                    v = (v << 8) + readByte(++m_ip);

                Block b;
                b.set<uint_t>(std::move(v));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<uint_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<uint_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 8 bytes integer");
            }
            return m_objects[m_ip].get<uint_t>();
        }

        micro_int_t BytecodeBlocksMaker::read2BytesInt()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                Block b;
                b.set<micro_int_t>(abc::setSign((micro_int_t)readXBytesInt(2), /* bytesCount */ 2));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<micro_int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<micro_int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 2 bytes integer");
            }
            return m_objects[m_ip].get<micro_int_t>();
        }

        smol_int_t BytecodeBlocksMaker::read4BytesInt()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                Block b;
                b.set<smol_int_t>(abc::setSign((smol_int_t)readXBytesInt(4), /* bytesCount */ 4));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<smol_int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<smol_int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 4 bytes integer");
            }
            return m_objects[m_ip].get<smol_int_t>();
        }

        int_t BytecodeBlocksMaker::read8BytesInt()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                Block b;
                b.set<int_t>(abc::setSign((int_t)readXBytesInt(8), /* bytesCount */ 8));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<int_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<int_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored 8 bytes integer");
            }
            return m_objects[m_ip].get<int_t>();
        }

        double BytecodeBlocksMaker::readDouble()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                smol_uint_t int_part = read4BytesInt();
                micro_int_t exp = abc::abs(read2BytesInt());
                exp = (exp > EXP_DOUBLE_LIMIT) ? EXP_DOUBLE_LIMIT : ((exp < -EXP_DOUBLE_LIMIT) ? -EXP_DOUBLE_LIMIT : exp);
                exp *= (exp & EXP_DOUBLE_SIGN) ? (-1) : (+1);

                Block b;
                b.set<double>(double(int_part) * std::pow(10, exp));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<double>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<double>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a double previously stored");
            }
            return m_objects[m_ip].get<double>();
        }

        str_t BytecodeBlocksMaker::readString()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                str_t work = "";
                ++m_ip;
                while (true)
                {
                    inst_t byte = readByte(m_ip++);
                    if (byte != 0x00)
                        work += byte;
                    else
                        break;
                }
                --m_ip;

                Block b;
                b.set<str_t>(std::move(work));
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<str_t>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<str_t>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a previously stored string");
            }
            return m_objects[m_ip].get<str_t>();
        }

        bool BytecodeBlocksMaker::readBool()
        {
            if (m_ip > m_size)
            {
                // read and register
                addr_t last = m_ip;

                Block b;
                b.set<bool>(readByte(++m_ip) > 0);
                m_objects[last] = b;
                m_size += (m_ip - last);

                return b.get<bool>();
            }
            if (m_typecheck)
            {
                if (!m_objects[m_ip].holds<bool>())
                    raiseException(Exception::CRITIC, "Type error when trying to retrieve a boolean previously stored");
            }
            return m_objects[m_ip].get<bool>();
        }

        void BytecodeBlocksMaker::clear()
        {
            m_size = 0;
            m_objects.clear();
        }

    } // namespace abc
}  // namespace kafe
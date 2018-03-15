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

        BytecodeBlocksMaker::BytecodeBlocksMaker(addr_t& ip, Bytecode& bytecode, ErrorHandler& errh) : m_ip(ip), m_bytecode(bytecode), m_errh(errh) {}

        BytecodeBlocksMaker::~BytecodeBlocksMaker() {}

        void BytecodeBlocksMaker::raiseException(int error, const std::string& msg)
        {
            m_errh.raiseException(error, msg, m_ip);
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
            return abc::setSign((micro_int_t)readXBytesInt(2), /* bytesCount */ 2);
        }

        smol_int_t BytecodeBlocksMaker::read4BytesInt()
        {
            return abc::setSign((smol_int_t)readXBytesInt(4), /* bytesCount */ 4);
        }

        int_t BytecodeBlocksMaker::read8BytesInt()
        {
            return abc::setSign((int_t)readXBytesInt(8), /* bytesCount */ 8);
        }

        double BytecodeBlocksMaker::readDouble()
        {
            smol_uint_t int_part = read4BytesInt();
            micro_int_t exp = read2BytesInt();
            exp = (exp > EXP_DOUBLE_LIMIT) ? EXP_DOUBLE_LIMIT : ((exp < -EXP_DOUBLE_LIMIT) ? -EXP_DOUBLE_LIMIT : exp);
            exp *= (exp & EXP_DOUBLE_SIGN) ? (-1) : (+1);

            return double(int_part) * std::pow(10, exp);
        }

        str_t BytecodeBlocksMaker::readString()
        {
            str_t work = "";
            while (true)
            {
                inst_t byte = readByte(++m_ip);
                if (byte != 0x00)
                    work += byte;
                else
                    break;
            }
            return work;
        }

        bool BytecodeBlocksMaker::readBool()
        {
            return readByte(++m_ip) > 0;
        }

        Value& BytecodeBlocksMaker::get2BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Int;
                m_bytecode.at(last).evaluated.set<int_t>(read2BytesInt());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::get4BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Int;
                m_bytecode.at(last).evaluated.set<int_t>(read4BytesInt());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::get8BytesInt()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Int;
                m_bytecode.at(last).evaluated.set<int_t>(read8BytesInt());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::getDouble()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Double;
                m_bytecode.at(last).evaluated.set<double>(readDouble());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::getString()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::String;
                m_bytecode.at(last).evaluated.set<str_t>(readString());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::getBool()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Bool;
                m_bytecode.at(last).evaluated.set<bool>(readBool());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

        Value& BytecodeBlocksMaker::getAddr()
        {
            addr_t last = m_ip;
            if (!m_bytecode.at(last).read)
            {
                // read and register
                m_bytecode.at(last).read = true;
                m_bytecode.at(last).evaluated.type = ValueType::Addr;
                m_bytecode.at(last).evaluated.set<addr_t>(read4BytesInt());
                m_bytecode.at(last).size = m_ip - last;

                return m_bytecode.at(last).evaluated;
            }
            m_ip += m_bytecode.at(last).size;
            return m_bytecode.at(last).evaluated;
        }

    } // namespace abc
}  // namespace kafe
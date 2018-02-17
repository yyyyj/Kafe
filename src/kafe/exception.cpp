#include <iostream>

#include "myexception.hpp"

namespace kafe
{
    std::string Exception::errorCodeToString(int error)
    {
        switch (error)
        {
        case Exception::CRITIC:
            return "CRITIC";

        case Exception::LOGIC:
            return "LOGIC";

        case Exception::RUNTIME:
            return "RUNTIME";

        case Exception::MALFORMED:
            return "MALFORMED";

        default:
            return "UNKNOWN";
        }
    }

    Exception::Exception(int error) : m_code(error), m_line(0), m_message("")
    {}

    Exception::Exception(int error, const std::string& message, addr_t line) :
        m_code(error)
        , m_line(line)
        , m_message(message)
    {}

    Exception::Exception(const Exception& other) :
        m_code(other.m_code)
        , m_line(other.m_line)
        , m_message(other.m_message)
    {}

    std::ostream& operator<<(std::ostream& os, const Exception& exc)
    {
        os << "[" << Exception::errorCodeToString(exc.m_code) << " @ byte no " << exc.m_line << "] " << exc.m_message;
        return os;
    }
}
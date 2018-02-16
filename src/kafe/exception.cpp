#include <iostream>

#include "myexception.hpp"

namespace kafe
{
    Exception::Exception(int error) : m_code(error), m_line(0), m_message("")
    {}

    Exception::Exception(int error, const std::string& message, int line) :
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
        os << "[#" << exc.m_code << " @ " << exc.m_line << "] " << exc.m_message;
        return os;
    }
}
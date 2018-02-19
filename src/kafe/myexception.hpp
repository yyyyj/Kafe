#ifndef kafe_myexception
#define kafe_myexception

#include <string>
#include "types.hpp"

namespace kafe
{
    class Exception
    {
    private:
        int m_code;
        addr_t m_line;
        std::string m_message;

    public:
        static const int CRITIC = 0;
        static const int LOGIC = 1;
        static const int RUNTIME = 2;
        static const int MALFORMED = 4;

        static std::string errorCodeToString(int);

        Exception() = delete;
        Exception(int);
        Exception(int, const std::string&, addr_t);
        Exception(const Exception&);
        int errorCode() const;
        friend std::ostream& operator<<(std::ostream&, const Exception&);

        bool operator==(const Exception&) const;
    };
}

#endif // kafe_myexception
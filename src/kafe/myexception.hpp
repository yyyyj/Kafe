#ifndef kafe_myexception
#define kafe_myexception

#include <string>

namespace kafe
{
    class Exception
    {
    private:
        int m_code;
        int m_line;
        std::string m_message;

    public:
        static const int LOGIC = 1;
        static const int RUNTIME = 2;
        static const int MALFORMED = 3;

        Exception() = delete;
        Exception(int);
        Exception(int, const std::string&, int);
        Exception(const Exception&);
        friend std::ostream& operator<<(std::ostream&, const Exception&);
    };
}

#endif // kafe_myexception
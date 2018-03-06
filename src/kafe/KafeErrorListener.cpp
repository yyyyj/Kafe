#include "KafeErrorListener.hpp"

namespace kafe
{
    KafeErrorListener::KafeErrorListener() : m_errCount(0)
    {}
    
    void KafeErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e)
    {
        m_errCount++;
        m_os << "\tLine " << line << ":" << charPositionInLine << " " << msg << std::endl;
    }
    
    void KafeErrorListener::resetStuff()
    {
        m_os.clear();
        m_errCount = 0;
    }
    
    std::ostream& operator<<(std::ostream& os, const KafeErrorListener& kerrlistener)
    {
        os << kerrlistener.m_os.str();
        return os;
    }
    
}  // namespace kafe
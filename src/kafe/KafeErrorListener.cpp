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

#include <kafe/KafeErrorListener.hpp>

namespace kafe
{
    KafeErrorListener::KafeErrorListener()
    {}
    
    void KafeErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e)
    {
        m_os << "\tLine " << line << ":" << charPositionInLine << " " << msg << std::endl;
    }
    
    void KafeErrorListener::resetStuff()
    {
        m_os.clear();
    }
    
    std::ostream& operator<<(std::ostream& os, const KafeErrorListener& kerrlistener)
    {
        os << kerrlistener.m_os.str();
        return os;
    }
    
}  // namespace kafe
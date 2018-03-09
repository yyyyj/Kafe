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

#ifndef kafe_kafeerrorlistener
#define kafe_kafeerrorlistener

#include "BaseErrorListener.h"

#include <sstream>
#include <iostream>

namespace kafe
{
    class KafeErrorListener : public antlr4::BaseErrorListener
    {
    private:
        std::stringstream m_os;
    
    public:
        KafeErrorListener();
        
        virtual void syntaxError(antlr4::Recognizer*, antlr4::Token*, size_t, size_t, const std::string&, std::exception_ptr) override;
        
        void resetStuff();
        
        friend std::ostream& operator<<(std::ostream&, const KafeErrorListener&);
    };
} // namespace kafe

#endif  // kafe_kafeerrorlistener
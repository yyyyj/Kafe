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
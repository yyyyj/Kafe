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

#ifndef kafe_state_refvar
#define kafe_state_refvar

#include <kafe/vm/value.hpp>

#include <variant>
#include <exception>
#include <stdexcept>

namespace kafe
{
    
    class RefVar
    {
    private:
        Value& m_v;
        
    public:
        RefVar() = delete;
        RefVar(Value&);
        ~RefVar();
        RefVar(const RefVar&);
        RefVar(RefVar&&);
        
        RefVar& operator=(RefVar&&);

        template <typename T> T& operator()()
        {
            // we are not using the facilities of mv.get<T>() because it would
            // create a default object if it does not hold the wanted type
            if (std::holds_alternative<T>(m_v.value))
                return std::get<T>(m_v.value);
            throw std::runtime_error("Can not get the wanted value");
        }
    };
    
}  // namespace kafe

#endif  // kafe_state_refvar
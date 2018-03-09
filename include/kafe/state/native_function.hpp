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

#ifndef kafe_state_fct
#define kafe_state_fct

namespace kafe
{

    class State;
    
    class Function
    {
    private:
        State& m_state;
        
    public:
        Function() = delete;
        Function(State&);
        ~Function();
        Function(const Function&);
        Function(Function&&);

        // execute the code and expect a value to be returned of type T
        template <typename T> T call()
        {}
        
        // execute the code without returning a value
        void operator()();
    };
    
}  // namespace kafe

#endif  // kafe_state_fct
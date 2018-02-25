#ifndef kafe_state_state
#define kafe_state_state

#include "../vm/vm.hpp"
#include "../parser.hpp"
#include "../types.hpp"
#include "function.hpp"
#include "refvar.hpp"

#include <string>

namespace kafe
{
    
    class State
    {
    private:
        
    public:
        State();
        ~State();
        State(const State&);
        
        void execFile(const std::string&);
        Function loadFile(const std::string&);
        Function loadString(const std::string&);
        
        Function operator()(const std::string&);
        RefVar& operator[](std::size_t index);
    };
    
}  // namespace kafe

#endif  // kafe_state_state
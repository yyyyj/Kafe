#ifndef kafe_state_state
#define kafe_state_state

#include <kafe/vm/vm.hpp>
#include <kafe/parser.hpp>
#include <kafe/types.hpp>
#include <kafe/state/native_function.hpp>
#include <kafe/state/refvar.hpp>

#include <string>
#include <unordered_map>
#include <exception>
#include <stdexcept>

namespace kafe
{
    
    class State
    {
    private:
        std::unordered_map<std::string, Value> m_vars;
        VM vm;

    public:
        State();
        ~State();
        State(const State&);
        
        void execFile(const std::string&);
        Function loadFile(const std::string&);
        Function loadString(const std::string&);
        
        void operator()(const std::string&);
        RefVar operator[](const std::string&);
    };
    
}  // namespace kafe

#endif  // kafe_state_state
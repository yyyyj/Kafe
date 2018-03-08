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
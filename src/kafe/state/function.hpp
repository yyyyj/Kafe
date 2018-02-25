#ifndef kafe_state_function
#define kafe_state_function

namespace kafe
{
    
    class Function
    {
    private:
        
    public:
        Function();
        ~Function()
        Function(const Function&);
        Function(Function&&);
        
        void operator()();
    };
    
}  // namespace kafe

#endif  // kafe_state_function
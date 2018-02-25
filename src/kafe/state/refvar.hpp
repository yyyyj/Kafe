#ifndef kafe_state_refvar
#define kafe_state_refvar

namespace kafe
{
    
    class RefVar
    {
    private:
        
    public:
        RefVar();
        ~RefVar();
        RefVar(const RefVar&);
        RefVar(RefVar&&);
        
        RefVar& operator=(RefVar&);
    };
    
}  // namespace kafe

#endif  // kafe_state_refvar
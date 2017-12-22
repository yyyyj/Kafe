# Coding guidelines

```cpp
namespace ns
{

    class Thing
    {
    private:
        int m_something;
        
        void privateMethod();

    public:
        Thing();
        ~Thing();
        
        void aPublicMethod();
    };

}  // namespace ns
```

```cpp
if (condition)
{
    /*
    multiline code to execute if condition is true
    */
}
else
    { /* single instruction code if condition == false */ }

for (std::size_t i=0; i < m_container.size(); ++i)
    { myFunction(i); }
```
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
    // ...
    // ...
    // ...
}
else
    { single instruction code if condition == false }

for (std::size_t i=0; i < m_container.size(); ++i)
    { myFunction(i); }
```

# Opening an issue

## New functionality

Add [idea] to the title of your issue. If you can, provide some code (either how to use the new functionality or how to implement it, or both).

Don't forget to add details : why do you think it could be a good idea to implement it, what does it bring...

## Reporting a bug

Give all the steps followed to get to the bug, and explain why you think it's a bug.

Don't forget to provide code.

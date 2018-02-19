#ifndef sygmei_fundb
#define sygmei_fundb

#include <unordered_map>
#include <string>

class Function
{
private:
    void (*m_function)();
    std::size_t argc;

public:
    template <class R, class ...A1>
    Function& operator=(R(*f)(A1...))
    {
        m_function = (void(*)()) f;
        argc = sizeof...(A1);
        return *this;
    }

    template <class R, class ...A1>
    R call(A1... a1) const
    {
        R(*f)(A1...) = (R(*)(A1...))(m_function);
        return (*f)(a1...);
    }

    std::size_t argCount() const
    {
        return argc;
    }
};

class FunctionDatabase
{
private:
    std::unordered_map<std::string, Function> m_functions;

public:
    template <class R, class ...A1>
    FunctionDatabase& add(std::string name, R(*f)(A1...))
    {
        m_functions[name] = f;
        return *this;
    }

    Function& operator[](const std::string& name)
    {
        return m_functions[name];
    }
    
    std::size_t size() const
    {
        return m_functions.size();
    }

    void clear()
    {
        m_functions.clear();
    }
};

#endif  // sygmei_fundb
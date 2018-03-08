#include <kafe/state/state.hpp>

namespace kafe
{
    
    State::State()
    {}
    
    State::~State()
    {}
    
    State::State(const State& other)
    {}

    void State::execFile(const std::string& filename)
    {}

    Function State::loadFile(const std::string& filename)
    {
        return Function(*this);
    }

    Function State::loadString(const std::string& code)
    {
        return Function(*this);
    }

    void State::operator()(const std::string& code)
    {}

    RefVar State::operator[](const std::string& key)
    {
        if (m_vars.find(key) != m_vars.end())
            return RefVar(m_vars[key]);
        throw std::runtime_error("Could not get the wanted key : " + key);
    }
    
}  // namespace kafe
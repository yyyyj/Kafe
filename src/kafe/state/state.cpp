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

    void State::registerFunction(const std::string& name, functionPtr fct)
    {
        m_vm.registerFunction(name, fct);
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
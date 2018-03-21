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
        std::ifstream file(filename);

        if (file.good())
        {
            std::string content = "";
            file >> content;
            file.close();
            Function f = loadString(content);
            return f;
        }
        throw std::runtime_error("Could not find the specified file : " + filename);
    }

    Function State::loadString(const std::string& code)
    {
        Parser kparser(code);
        kparser.parse();
        m_vm.load(kparser.getBytecode());
        m_vm.exec();
        return Function(*this);  // wut ?
    }

    void State::registerFunction(const std::string& name, functionPtr fct)
    {
        m_vm.registerFunction(name, fct);
    }

    void State::operator()(const std::string& code)
    {
        (loadString(code))();
    }

    RefVar State::operator[](const std::string& key)
    {
        if (m_vars.find(key) != m_vars.end())
            return RefVar(m_vars[key]);  // wut wut wut ? need ref on refvar ???
        throw std::runtime_error("Could not get the wanted variable : " + key);
    }
    
}  // namespace kafe
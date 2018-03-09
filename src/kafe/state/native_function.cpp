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

#include <kafe/state/native_function.hpp>
#include <kafe/state/state.hpp>

namespace kafe
{

    Function::Function(State& state) : m_state(state) {}

    Function::~Function() {}

    Function::Function(const Function& other) : m_state(other.m_state) {}

    Function::Function(Function&& other) : m_state(std::move(m_state)) {}

    void Function::operator()()
    {}
    
}
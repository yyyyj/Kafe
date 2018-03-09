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

#include <kafe/state/refvar.hpp>

namespace kafe
{

    RefVar::RefVar(Value& val) : m_v(val) {}

    RefVar::~RefVar() {}

    RefVar::RefVar(const RefVar& other) : m_v(other.m_v) {}

    RefVar::RefVar(RefVar&& other) : m_v(std::move(other.m_v)) {}

    RefVar& RefVar::operator=(RefVar&& other)
    {
        if (this != &other)
            m_v = std::move(other.m_v);
        return *this;
    }
    
}
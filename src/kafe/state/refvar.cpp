#include "refvar.hpp"

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
#include <kafe/native_function.hpp>
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
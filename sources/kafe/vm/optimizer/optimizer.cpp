#include "optimizer.hpp"

namespace kafe
{

    namespace Optimizer
    {

        Main::Main() :
            m_current_block(0)
        {}

        Main::~Main() {}

        void Main::run(bytecode_t bytecode)
        {
            //
        }

        const IntermediateValue& Main::getNextBlock()
        {
            if (m_current_block + 1 < m_blocks.size())
                return m_blocks[++m_current_block];

            throw std::runtime_error("Trying to get an out of bound bloc of optimized bytecode");
        }

        std::size_t Main::countBlocks() const
        {
            return m_blocks.size();
        }

    }  // namespace Optimizer

}  // namespace kafe

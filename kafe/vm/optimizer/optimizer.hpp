#ifndef kafe_vm_optimizer_optimizer
#define kafe_vm_optimizer_optimizer

#include "value.hpp"
#include "../instructions.hpp"
#include "../../types.hpp"

#include <vector>
#include <exception>
#include <stdexcept>

namespace kafe
{

    namespace Optimizer
    {

        class Main
        {
        private:
            std::size_t m_current_block;
            std::vector<IntermediateValue> m_blocks;

        public:
            Main();
            ~Main();

            void clear();

            void run(bytecode_t bytecode);
            const IntermediateValue& getNextBlock();
            std::size_t countBlocks() const;
        };

    }  // namespace Optimizer

}  // namespace kafe


#endif // kafe_vm_optimizer_optimizer

#ifndef kafe_vm_optimizer_value
#define kafe_vm_optimizer_value

#include "../../libs/variant.hpp"
#include "../value.hpp"
#include "../../types.hpp"

namespace kafe
{

    namespace Optimizer
    {

        struct BasicInstructionInfo
        {
            inst_t instruction_code;
        };

        struct IntermediateValue
        {
            mpark::variant<kafe::Value, BasicInstructionInfo> val;
            std::size_t pos;
        };

    }  // namespace Optimizer

}  // namespace kafe


#endif // kafe_vm_optimizer_value

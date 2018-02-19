#ifndef kafe_vm_lib
#define kafe_vm_lib

#include <sygmei/functiondb.hpp>
#include <vector>
#include <string>

#include "instructions.hpp"
#include "value.hpp"
#include "../exceptions.hpp"

namespace kafe
{
    namespace StdLibVM
    {
        static const std::vector<std::string> inst_to_name = {
            "add", "sub", "div", "mul", "mod", "inc", "dec", "neg" // ...
        };

        Value _add(const Value&, const Value&);

        void load(FunctionDatabase&);
    }
}

#endif  // kafe_vm_lib
#ifndef kafe_vm_lib
#define kafe_vm_lib

#include <sygmei/functiondb.hpp>
#include <vector>
#include <string>

#include "instructions.hpp"
#include "value.hpp"
#include "../exc.hpp"

namespace kafe
{
    namespace StdLibVM
    {
        static const std::vector<std::string> inst_to_name = {
            "add", "sub", "div", "mul", "mod", "inc", "dec", "neg" // ...
        };

        Value procName(int2B_t);

        Value _doStuff(const Value&, const Value&);
        Value _add(const Value&, const Value&);

        void load(FunctionDatabase&);
    }
}

#endif  // kafe_vm_lib
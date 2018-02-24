#ifndef kafe_vm_lib
#define kafe_vm_lib

#include <sygmei/functiondb.hpp>
#include <vector>
#include <string>

#include "instructions.hpp"
#include "../exc.hpp"
#include "value.hpp"

namespace kafe
{
    namespace StdLibVM
    {
        static std::vector<std::string> inst_to_name = {
            "add", "sub", "div", "mul", "mod", "inc", "dec", "neg" // ...
        };

        Value procName(micro_uint_t);

        Value _doStuff(const Value&, const Value&);
        Value _add(const Value&, const Value&);

        void load(FunctionDatabase&);
    }
}

#endif  // kafe_vm_lib
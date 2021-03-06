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

#ifndef kafe_vm_lib
#define kafe_vm_lib

#include <sygmei/functiondb.hpp>
#include <vector>
#include <string>

#include <kafe/vm/instructions.hpp>
#include <kafe/KafeException.hpp>
#include <kafe/vm/value.hpp>

namespace kafe
{
    namespace StdLibVM
    {
        static std::vector<std::string> inst_to_name = {
            "add", "sub", "div", "mul", "mod", "inc", "dec", "neg",
            "binand", "binnor", "binnot", "lshift", "rshift", "binxor",
            "and", "or", "not", "lw", "le", "gr", "ge", "eq", "ne"
        };

        Value procName(abc::micro_uint_t);

        Value _doStuff(const Value&, const Value&);

        Value _add(const Value&, const Value&);
        Value _sub(const Value&, const Value&);
        Value _div(const Value&, const Value&);
        Value _mul(const Value&, const Value&);
        Value _mod(const Value&, const Value&);
        Value _inc(const Value&, const Value&);
        Value _dec(const Value&, const Value&);
        Value _neg(const Value&, const Value&);
        Value _binand(const Value&, const Value&);
        Value _binnor(const Value&, const Value&);
        Value _binnot(const Value&, const Value&);
        Value _lshift(const Value&, const Value&);
        Value _rshift(const Value&, const Value&);
        Value _binxor(const Value&, const Value&);
        Value _and(const Value&, const Value&);
        Value _or(const Value&, const Value&);
        Value _not(const Value&, const Value&);
        Value _lw(const Value&, const Value&);
        Value _le(const Value&, const Value&);
        Value _gr(const Value&, const Value&);
        Value _ge(const Value&, const Value&);
        Value _eq(const Value&, const Value&);
        Value _ne(const Value&, const Value&);

        void load(FunctionDatabase&);
    }
}

#endif  // kafe_vm_lib
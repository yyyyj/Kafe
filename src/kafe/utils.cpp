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

#include <kafe/utils.hpp>

namespace kafe
{
    namespace abc
    {

        std::string hexstr(const unsigned& n)
        {
            std::ostringstream stm;
            stm << "0x" << std::hex << n;
            return stm.str();
        }

    }  // namespace abc
}  // namespace kafe

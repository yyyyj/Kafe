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

#ifndef kafe_plugins_packager
#define kafe_plugins_packager

#include <kafe/plugins/loader.hpp>
#include <kafe/api.hpp>

#include <string>

namespace kafe
{
    namespace abc
    {
        
        DLLModule loadPlugin(const std::string& name);
        
    }
}

#endif  // kafe_plugins_packager
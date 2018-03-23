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

#include <kafe/plugins/packager.hpp>

#include <iostream>
#include <exception>
#include <stdexcept>

namespace kafe
{
    namespace abc
    {
        
        DLLModule loadPlugin(const std::string& name)
        {
            try
            {
                DLLModule mod(name);
                if (mod.requiredKafeAPI() != KAFE_API_VERSION)
                {
                    std::cerr << "The wanted API version for the plugin " << mod.getName() << "(" << mod.getVersion() << ") isn't the one currently used" << std::endl;
                    throw std::runtime_error("API Version not matching");
                }
                return mod;
            }
            catch(std::system_error& se)
            {
                std::cerr << "Error: " << se.code().value() << "\n";
                std::cerr << "Message: " << se.code().message() << "\n";
                std::cerr << "What: " << se.what() << "\n";
                throw se;
            }
        }
        
    }
}
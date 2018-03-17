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

#ifndef kafe_vm_errorhandler
#define kafe_vm_errorhandler

#include <vector>
#include <string>
#include <iostream>

#include <kafe/types.hpp>
#include <kafe/KafeException.hpp>

namespace kafe
{
    namespace abc
    {

        class ErrorHandler
        {
        private:
            std::vector<Exception> m_exceptions;

        public:
            ErrorHandler();
            ~ErrorHandler();

            void raiseException(const Exception&);
            void raiseException(int error, const std::string& message, addr_t ip);
            void displayTraceback();
            bool empty() const;
            void clear();
        };

    }  // namespace abc
}  // namespace kafe

#endif  // kafe_vm_errorhandler
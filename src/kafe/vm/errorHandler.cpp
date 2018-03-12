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

#include <kafe/vm/errorHandler.hpp>

namespace kafe
{

    ErrorHandler::ErrorHandler() {}

    ErrorHandler::~ErrorHandler()
    {
        if (!empty())
            displayTraceback();
        clear();
    }

    void ErrorHandler::raiseException(const Exception& exc)
    {
        m_exceptions.push_back(exc);
        if (exc.errorCode() == Exception::CRITIC)
            displayTraceback();
    }

    void ErrorHandler::raiseException(int error, const std::string& message, addr_t ip)
    {
        raiseException(Exception(error, message, ip));
    }

    void ErrorHandler::displayTraceback()
    {
        // display exception list
        std::cerr << std::endl << "Traceback (most recent call last) :" << std::endl;
        for (auto& e : m_exceptions)
            std::cerr << '\t' << e << std::endl;
        // exit the program
        throw std::runtime_error("Fatal error occured, see traceback");
    }

    bool ErrorHandler::empty() const
    {
        return m_exceptions.empty();
    }

    void ErrorHandler::clear()
    {
        m_exceptions.clear();
    }

}  // namespace kafe
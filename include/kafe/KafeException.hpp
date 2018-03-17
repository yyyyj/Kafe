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

#ifndef kafe_exc
#define kafe_exc

#include <string>
#include <kafe/types.hpp>

namespace kafe
{
    namespace abc
    {

        class Exception
        {
        private:
            int m_code;
            addr_t m_line;
            std::string m_message;

        public:
            static const int CRITIC = 0;
            static const int LOGIC = 1;
            static const int RUNTIME = 2;
            static const int MALFORMED = 4;

            static std::string errorCodeToString(int);

            Exception() = default;
            Exception(int);
            Exception(int, const std::string&, addr_t);
            Exception(const Exception&);
            int errorCode() const;
            void setLine(addr_t);
            friend std::ostream& operator<<(std::ostream&, const Exception&);

            bool operator==(const Exception&) const;
        };

    }  // namespace abc
}  // namespace kafe

#endif // kafe_exc
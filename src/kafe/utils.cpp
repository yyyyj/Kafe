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

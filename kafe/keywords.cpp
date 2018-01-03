#include "keywords.hpp"

namespace kafe
{

    namespace kw
    {
        const std::vector<std::string> keywords = {
            "struct", "fun", "ret", "end",
            "dyn",
            "for", "while", "if",
            "in",
        };

        const std::vector<std::string> bloc_opening_kw = {
            "struct", "fun", "dyn", "for", "while", "if",
        };

    }  // namespace kw

}  // namespace kafe

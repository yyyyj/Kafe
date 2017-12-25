#ifndef kafe_ast
#define kafe_ast

#include <vector>

#include "../lexer/tokens.hpp"

namespace kafe
{

    namespace ast
    {

        struct LinearNode
        {
            std::vector<KafeToken> components;
        };

        struct Bloc
        {
            LinearNode head;
            std::vector<LinearNode> body;
        };

    }  // namespace ast

}  // namespace kafe

#endif // kafe_ast

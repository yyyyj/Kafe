#ifndef kafe_parser
#define kafe_parser

#include "../lexer/lexer.hpp"
#include "../types.hpp"
#include "../ast/ast.hpp"
#include "../keywords.hpp"

#include <vector>

namespace kafe
{

    typedef std::vector<ast::Bloc> ast_t;

    class Parser
    {
    private:
        Lexer& m_lexer;
        ast_t ast;

    public:
        Parser(Lexer& lexer);
        ~Parser();

        void composeAST();
        ast_t getAST();
        bytecode_t generateBytecode();
    };

}  // namespace kafe

#endif // kafe_parser

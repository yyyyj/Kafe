#include "parser.hpp"

namespace kafe
{

    Parser::Parser(Lexer& lexer) :
        m_lexer(lexer)
    {}

    Parser::~Parser() {}

    void Parser::composeAST()
    {
        while(true)
        {
            KafeToken tok = m_lexer.getNextToken();

            if (tok == Lexer::EndOfFile)
                break;
            if (tok.getType() == KafeTokenType::Whitespace && tok.getValue() != "\n")
                continue;

            /*if (tok.getValue() in kw::bloc_opening_kw)
            {
                // create bloc
            }
            else
            {
                // create linear node or add to the last bloc/linear node (depending on the lines break)
            }*/
        }
    }

    ast_t Parser::getAST()
    {
        return ast;
    }

    bytecode_t Parser::generateBytecode()
    {
        bytecode_t bytecode;

        return bytecode;
    }

}  // namespace kafe

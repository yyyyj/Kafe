#include "parser.hpp"

namespace kafe
{


    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool ast)
    { }

    void testANTLR()
    {
        std::string line;
        std::ifstream kafeFile("examples/plaintext/all_kw_test.kafe");
        if (kafeFile.is_open())
        {
            antlr4::ANTLRInputStream input(kafeFile);

            // lexing
            KafeErrorListener lexer_err_listener;
            KafeLexer lexer(&input);
            lexer.removeErrorListeners();
            lexer.addErrorListener(&lexer_err_listener);

            antlr4::CommonTokenStream tokens(&lexer);
            tokens.fill();
            std::size_t lexerErr = lexer.getNumberOfSyntaxErrors();
            if (lexerErr > 0)
            {
                std::cerr << "Lexer syntax error" << (lexerErr > 1 ? "s" : "") << " (" << lexerErr << ")" << std::endl;
                std::cerr << lexer_err_listener << std::endl;
            }

            // parsing
            KafeErrorListener parser_err_listener;
            KafeParser parser(&tokens);
            parser.removeErrorListeners();
            parser.addErrorListener(&parser_err_listener);

            antlr4::tree::ParseTree* tree = parser.chunk();
            std::size_t parserErr = parser.getNumberOfSyntaxErrors();
            if (parserErr > 0)
            {
                std::cerr << "Parser syntax error" << (parserErr > 1 ? "s" : "") << " (" << parserErr << ")" << std::endl;
                std::cerr << parser_err_listener << std::endl;
            }
            
            // displaying AST
            std::cout << tree->toStringTree(&parser) << std::endl;

            kafeFile.close();
        }
        /*else
            { throw std::runtime_error("Could not open wanted file"); }*/
    }

}  // namespace kafe

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

#include <kafe/parser.hpp>

namespace kafe
{


    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool save_ast, bool disable_errors)
    {
        bool flag_errors = false;
        if (!files.empty())
        {
            for (auto file : files)
            {
                std::ifstream kafeFile(file);
                if (kafeFile.is_open())
                {
                    antlr4::ANTLRInputStream input(kafeFile);
                    // lexing
                    KafeErrorListener lexer_err_listener;
                    KafeLexer lexer(&input);
                    lexer.removeErrorListeners();
                    lexer.addErrorListener(&lexer_err_listener);
                    // lexer error handling
                    antlr4::CommonTokenStream tokens(&lexer);
                    tokens.fill();
                    std::size_t lexerErr = lexer.getNumberOfSyntaxErrors();
                    if (lexerErr > 0)
                    {
                        if (!disable_errors)
                        {
                            std::cerr << "Lexer syntax error" << (lexerErr > 1 ? "s" : "") << " (" << lexerErr << ")" << std::endl;
                            std::cerr << lexer_err_listener << std::endl;
                        }
                        flag_errors = true;
                        break;
                    }
                    // parsing
                    KafeErrorListener parser_err_listener;
                    KafeParser parser(&tokens);
                    parser.removeErrorListeners();
                    parser.addErrorListener(&parser_err_listener);
                    // parsing error handling
                    antlr4::tree::ParseTree* tree = parser.chunk();
                    std::size_t parserErr = parser.getNumberOfSyntaxErrors();
                    if (parserErr > 0)
                    {
                        if (!disable_errors)
                        {
                            std::cerr << "Parser syntax error" << (parserErr > 1 ? "s" : "") << " (" << parserErr << ")" << std::endl;
                            std::cerr << parser_err_listener << std::endl;
                        }
                        flag_errors = true;
                        break;
                    }
                    // saving AST
                    if (save_ast)
                    {
                        std::ofstream output_for_ast(file + ".ast");
                        output_for_ast << tree->toStringTree(&parser);
                        output_for_ast.close();
                    }

                    kafeFile.close();
                }
                else
                {
                    std::cerr << "Can not open `" << file << "`" << std::endl;
                    flag_errors = true;
                    break;
                }
            }
        }
        else
        {
            std::cerr << "No input file(s). Aborting" << std::endl;
            flag_errors = true;
        }

        if (flag_errors)
            exit(1);
    }

    void testANTLR()
    {
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

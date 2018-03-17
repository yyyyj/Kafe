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

#include <kafe/parser/parser.hpp>
#include <kafe/parser/visitor.hpp>

namespace kafe
{

    Parser::Parser(std::ifstream& file) : m_mode(Parser::DEFAULT), m_input(file), m_ast("")
    {}

    Parser::Parser(const std::string& code) : m_mode(Parser::DEFAULT), m_input(code), m_ast("")
    {}

    Parser::~Parser()
    {}

    void Parser::parse(bool disable_errors, bool save_ast)
    {
        // lexing
        KafeLexer lexer(&m_input);
        lexer.removeErrorListeners();
        lexer.addErrorListener(&m_lexer_err_listener);
        antlr4::CommonTokenStream tokens(&lexer);
        tokens.fill();

        std::size_t lexerErr = lexer.getNumberOfSyntaxErrors();
        if (lexerErr > 0)
        {
            std::cerr << "Lexer syntax error" << (lexerErr > 1 ? "s" : "") << " (" << lexerErr << ")" << std::endl;
            if (!disable_errors)
                std::cerr << m_lexer_err_listener << std::endl;
            exit(1);
        }

        // parsing
        KafeParser parser(&tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(&m_parser_err_listener);
        antlr4::tree::ParseTree* tree = parser.chunk();

        std::size_t parserErr = parser.getNumberOfSyntaxErrors();
        if (parserErr > 0)
        {
            std::cerr << "Parser syntax error" << (parserErr > 1 ? "s" : "") << " (" << parserErr << ")" << std::endl;
            if (!disable_errors)
                std::cerr << m_parser_err_listener << std::endl;
            exit(1);
        }

        if (save_ast)
            m_ast = tree->toStringTree(&parser);

        abc::Visitor visitor(&m_gen);
        visitor.visit(tree);

        // organize bytecode generator code (functions calls, variables, structures definitions, halt...)
    }

    void Parser::setMode(int mode)
    {
        m_mode = mode;
    }

    const bytecode_t& Parser::getBytecode()
    {
        return m_bytecode;
    }

    const std::string& Parser::getAST()
    {
        return m_ast;
    }

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
                    Parser kparser(kafeFile);
                    kparser.parse(disable_errors);

                    if (save_ast)
                    {
                        std::ofstream out(file + ".ast");
                        out << kparser.getAST();
                        out.close();
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
            Parser kparser(kafeFile);
            kparser.setMode(Parser::DEBUG);
            kparser.parse();

            std::cout << kparser.getAST() << std::endl;

            kafeFile.close();
        }
    }

}  // namespace kafe

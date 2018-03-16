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

    Parser::Parser(std::ifstream& file) : m_input(file), m_ast(""), m_tree(nullptr), m_parser(nullptr)
    {}

    Parser::Parser(const std::string& code) : m_input(code), m_ast(""), m_tree(nullptr), m_parser(nullptr)
    {}

    Parser::~Parser()
    {
        if (m_tree != nullptr)
            delete m_tree;
        if (m_parser != nullptr)
            delete m_parser;
    }

    void Parser::parse(bool disable_errors)
    {
        // lexing
        KafeErrorListener lexer_err_listener;
        KafeLexer lexer(&m_input);
        lexer.removeErrorListeners();
        lexer.addErrorListener(&lexer_err_listener);
        antlr4::CommonTokenStream tokens(&lexer);
        tokens.fill();

        std::size_t lexerErr = lexer.getNumberOfSyntaxErrors();
        if (lexerErr > 0)
        {
            std::cerr << "Lexer syntax error" << (lexerErr > 1 ? "s" : "") << " (" << lexerErr << ")" << std::endl;
            if (!disable_errors)
                std::cerr << lexer_err_listener << std::endl;
            exit(1);
        }

        // parsing
        KafeErrorListener parser_err_listener;
        m_parser = new KafeParser(&tokens);
        parser->removeErrorListeners();
        parser->addErrorListener(&parser_err_listener);
        m_tree = parser->chunk();

        std::size_t parserErr = parser->getNumberOfSyntaxErrors();
        if (parserErr > 0)
        {
            std::cerr << "Parser syntax error" << (parserErr > 1 ? "s" : "") << " (" << parserErr << ")" << std::endl;
            if (!disable_errors)
                std::cerr << parser_err_listener << std::endl;
            exit(1);
        }
    }

    void Parser::toBytecode(const std::string& fn)
    {
        // do stuff
    }

    std::string Parser::getAST()
    {
        return m_tree->toStringTree(m_parser);
    }

    void Parser::toStringTree()
    {
        std::cout << m_tree->toStringTree(m_parser) << std::endl;
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
                    kparser.toBytecode(file);

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
            kparser.parse();
            
            // displaying AST
            kparser.toStringTree();

            kafeFile.close();
        }
    }

}  // namespace kafe

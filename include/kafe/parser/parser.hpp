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

#ifndef kafe_parser
#define kafe_parser

// must be included before everything else to avoid `ERRORS` in ATNSimulator to be replaced by 0 thanks to a shitty macro
#include "antlr4-runtime.h"

#include <kafe/constants.hpp>

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <memory>
#include <termcolor.hpp>

#include <kafe/generated/KafeLexer.h>
#include <kafe/generated/KafeParser.h>
#include <kafe/KafeErrorListener.hpp>
#include <kafe/parser/visitor.hpp>
#include <kafe/types.hpp>
#include <kafe/parser/generator.hpp>

namespace kafe
{

    class Parser
    {
    private:
        int m_mode;
        KafeErrorListener m_lexer_err_listener;
        KafeErrorListener m_parser_err_listener;
        antlr4::ANTLRInputStream m_input;
        bytecode_t m_bytecode;
        std::string m_ast;
        abc::Generator m_gen;

    public:
        Parser(std::ifstream&);
        Parser(const std::string&);
        ~Parser();

        void parse(bool disable_errors=false, bool save_ast=false);
        /*
        *   https://github.com/Gabbell/CommandLineInterpreter/blob/master/OSMini/CommandLineInterpreter.cpp#L67-L72
        *   https://github.com/Gabbell/CommandLineInterpreter/blob/master/OSMini/Visitor.h
        *   https://github.com/flashpixx/DateformatParser/blob/master/src/ASTListener.cpp#L38
        *   https://github.com/bajdcc/MyScript/search?utf8=?&q=walk&type=
        *   https://github.com/Gabbell/CommandLineInterpreter/tree/master/OSMini
        *   https://github.com/JaapSuter/Tard/blob/8d92087024d959ec4044c0e404330a0c87cbbb38/src/compiler.cpp
        *   https://github.com/JaapSuter/Tard/blob/8d92087024d959ec4044c0e404330a0c87cbbb38/generated_src/tard_parser.cpp
        *   
        */

        void setMode(int);
        const bytecode_t& getBytecode();
        const std::string& getAST();

        static const int DEFAULT = 0;
        static const int DEBUG = 1 << 1;
    };

    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool save_ast=false, bool disable_errors=false);

    void testANTLR();

}  // namespace kafe

#endif // kafe_parser

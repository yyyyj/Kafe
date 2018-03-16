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
#include <termcolor.hpp>

#include <kafe/parser/KafeLexer.h>
#include <kafe/parser/KafeParser.h>
#include <kafe/KafeErrorListener.hpp>

namespace kafe
{

    class Parser
    {
    private:
        antlr4::ANTLRInputStream m_input;
        antlr4::tree::ParseTree* m_tree;
        KafeParser* m_parser;

    public:
        Parser(std::ifstream&);
        Parser(const std::string&);
        ~Parser();

        void parse(bool disable_errors=false);
        void toBytecode(const std::string& fn);

        std::string getAST();
        void toStringTree();
    };

    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool save_ast=false, bool disable_errors=false);

    void testANTLR();

}  // namespace kafe

#endif // kafe_parser

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

    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool save_ast=false, bool disable_errors=false);

    void testANTLR();

}  // namespace kafe

#endif // kafe_parser

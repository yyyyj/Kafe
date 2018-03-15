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

#include <clipp.hpp>
#include <iostream>
#include <vector>
#include <string>

#include <kafe/kafe.hpp>
#include "tests/tests.hpp"

int getDebugMode(bool debug, bool interactive, bool experimental)
{
    int debug_mode = 0;
    if (debug)
        debug_mode |= kafe::VM::FLAG_BASIC_DEBUG;
    if (interactive)
        debug_mode |= kafe::VM::FLAG_INTERACTIVE;
    if (experimental)
        debug_mode |= kafe::VM::FLAG_EXPERIMENTAL;

    return debug_mode;
}

int main(int argc, char* argv[])
{
    using namespace clipp;

    enum class mode {help, build, exec, tests, version};
    mode selected;
    std::vector<std::string> infiles;
    std::string output_bytecode_file = "";
    bool display_ast_flag = false;
    std::string input_file = "";
    bool debug = false;
    bool interactive = false;
    bool experimental = false;
    std::vector<std::string> wrong;

    auto cli = (
                command("--help").set(selected, mode::help)
                | (command("build").set(selected, mode::build),
                    values("file", infiles)
                    ,
                    required("-o", "--out") & value("outfile", output_bytecode_file)
                    ,
                    (option("-a", "--ast").set(display_ast_flag) % "Save the generated AST to <file>.ast")
                 )
                | (
                   (command("exec").set(selected, mode::exec)
                       ,
                        value("file", input_file)
                     )
                    | (command("tests").set(selected, mode::tests))
                    ,
                    (option("-d", "--debug").set(debug) % "Enable debug mode")
                    ,
                    (option("-i", "--interactive").set(interactive) % "Start a CLI to be able to execute a file instruction per instruction")
                    ,
                    (option("-E", "--experimental").set(experimental) % "Enable experimental features")
                )
                | (command("--version").set(selected, mode::version) % "Display version number"),
                any_other(wrong)
                );

    auto fmt = doc_formatting{}
        .start_column(8)          // column where usage lines and documentation starts
        .doc_column(36)           // parameter docstring start col
        .indent_size(2)           // indent of documentation lines for children of a documented group
        .split_alternatives(true) // split usage into several lines for large alternatives
    ;

    if (parse(argc, argv, cli) && wrong.empty())
    {
        switch (selected)
        {
        default:
        case mode::help:
            std::cerr << make_man_page(cli, argv[0], fmt).append_section("LICENSE", "        Mozilla Public License 2.0")
                      << std::endl;
            return 0;

        case mode::build:
            // kafe::generateBytecode(infiles, output_bytecode_file, optimize_flag, display_ast_flag);
            break;

        case mode::exec:
        {
            kafe::VM vm;
            vm.setMode(getDebugMode(debug, interactive, experimental));
            vm.execFromFile(input_file);
            break;
        }

        case mode::tests:
            std::cerr << "antlr" << std::endl;
            kafe::testANTLR();
            std::cerr << "end" << std::endl;
            return start_tests(getDebugMode(debug, interactive, experimental));

        case mode::version:
            std::cerr << "Kafe " << kafe::abc::beautifyVersionNumber(KAFE_API_VERSION) << std::endl;
            break;
        }
    }
    else
    {
        for (const auto& arg : wrong)
            std::cerr << "'" << arg << "'" << " ins't a valid argument" << std::endl;
        std::cerr << "Usage:" << std::endl << usage_lines(cli, argv[0], fmt) << std::endl
                  << "Options:" << std::endl << documentation(cli, fmt) << std::endl
                  << "LICENSE" << std::endl << "        Mozilla Public License 2.0" << std::endl;
    }

    return 0;
}

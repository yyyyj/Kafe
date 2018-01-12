#include <iostream>
#include <string>

#include "kafe/kafe.hpp"
#include "tests.hpp"

int main(int argc, char* argv[])
{
    using namespace clipp;

    bool help = false, tests = false;
    int debug_mode = 0;
    std::string fname = "", fnsource = "", astsource = "";

    auto cli = (
                option("-f", "--file")    & value("Input bytecode", fname)        % "Input bytecode file to execute",
                option("-c", "--compile") & value("Input file", fnsource)         % "Input source code file to compile into bytecode",
                option("--ast")           & value("Input file => AST", astsource) % "Generate the AST of the given kafe source code file and save it to SOURCE.ast",
                option("-d", "--debug")   & value("Debug mode", debug_mode) % "Debug mode for the VM",
                option("--tests").set(tests)                                % "Start all the tests",
                option("-h", "--help").set(help)                            % "Display help"
                );

    if (parse(argc, argv, cli))
    {
        if (help)
        {
            std::cout << make_man_page(cli, argv[0]) << std::endl;
            exit(0);
        }

        if (tests)
        {
            exit(start_tests(debug_mode));
        }

        if (fname != "")
        {
            kafe::VM vm;
            vm.execFromFile(fname);
        }

        if (fnsource != "")
        {
            kafe::VM vm;
            kafe::generateBytecode(fnsource);
            vm.execFromFile(fnsource + ".kfb");
            vm.exec();
        }

        if (astsource != "")
        {
            kafe::generateAndSaveAST(astsource);
        }
    }

    return 0;
}

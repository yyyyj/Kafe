#include <iostream>
#include <string>

#include "kafe/kafe.hpp"
#include "tests.hpp"

int main(int argc, char* argv[])
{
    std::cout << argc << " ";
    for (int i=0; i < argc; ++i)
        { std::cout << argv[i] << " "; }
    std::cout << std::endl;

    using namespace clipp;

    bool help = false;
    bool tests = false;
    int debug_mode = 0;
    std::string fname = "";

    auto cli = (
                option("-f", "--file")  & value("Input file", fname)      % "Input file to execute",
                option("-d", "--debug") & value("Debug mode", debug_mode) % "Debug mode for the VM",
                option("--tests").set(tests)                              % "Start all the tests",
                option("-h", "--help").set(help)                          % "Display help"
                );

    if (parse(argc, argv, cli))
    {
        if (help)
        {
            std::cout << make_man_page(cli, argv[0]) << std::endl;
            exit(0);
        }
        if (tests)
            { exit(start_tests(debug_mode)); }
    }

    return 0;
}

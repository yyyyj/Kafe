#include <iostream>
#include <fstream>
#include <string>

#include "kafe/kafe.hpp"
#include "tests.hpp"

int main(int argc, char** argv)
{
    try
    {
        // see https://github.com/jarro2783/cxxopts/blob/master/src/example.cpp
        cxxopts::Options options(argv[0], " - The Kafe programming language interpreter");
        options.add_options()
            ("f,file", "Input file", cxxopts::value<std::string>())
            ("d,debug", "VM debug mode", cxxopts::value<int>())
            ("tests", "Start all the tests")
            ("help", "Print help")
            ;
        options.parse_positional({"file", "debug"});
        cxxopts::ParseResult result = options.parse(argc, argv);

        int debug_mode = 0;
        std::string fname = "";

        if (result.count("help"))
        {
            std::cout << options.help({""}) << std::endl;
            exit(0);
        }
        if (result.count("tests"))
        {
            start_tests(debug_mode);
            exit(0);
        }
        if (result.count("f"))
            { fname = result["f"].as<std::string>(); }
        if (result.count("d"))
            { debug_mode = result["d"].as<int>(); }
    }
    catch (const cxxopts::OptionException& e)
    {
        std::cout << "Error parsing options : " << e.what() << std::endl;
        exit(1);
    }

    return 0;
}

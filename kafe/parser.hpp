#ifndef kafe_parser
#define kafe_parser

#include "constants.hpp"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

namespace kafe
{

    namespace internal
    {

        // well don't do this at home because I am not really sure it will work on any system with python installed but hmmf
        #ifdef RUNNING_POSIX
        constexpr std::string pythonCMD = "python3";
        #endif
        #ifdef RUNNING_WIN
        constexpr std::string pythonCMD = "python";
        #endif

        std::string exec(const char* cmd);
        std::string execScript(const std::string& script);

    }  // namespace internal

    void generateAndSaveAST(const std::string& filename);
    void generateBytecode(const std::string& filename);

}  // namespace kafe

#endif // kafe_parser

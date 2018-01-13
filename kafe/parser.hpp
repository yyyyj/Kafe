#ifndef kafe_parser
#define kafe_parser

#include "constants.hpp"

#ifdef __STRICT_ANSI__
    #undef __STRICT_ANSI__
#endif // __STRICT_ANSI__

#include <stdio.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <array>

#ifdef RUNNING_WIN
    #define popen _popen
    #define pclose _pclose
#endif // RUNNING_WIN

namespace kafe
{

    namespace internal
    {

        // well don't do this at home because I am not really sure it will work on any system with python installed but hmmf
        #ifdef RUNNING_POSIX
        constexpr const char* pythonCMD = "python3";
        #endif
        #ifdef RUNNING_WIN
        constexpr const char* pythonCMD = "python";
        #endif

        std::string exec(const char* cmd);
        std::string execScript(const std::string& script);

    }  // namespace internal

    void generateAndSaveAST(const std::string& filename);
    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool optimize=false, bool ast=false);

}  // namespace kafe

#endif // kafe_parser

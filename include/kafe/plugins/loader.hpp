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

#ifndef kafe_dll_loader
#define kafe_dll_loader

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define RUNNING_WIN
    #include <Windows.h>
#endif // defined

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) && defined(__MACH__)
    // linux, unix and apple systems should be recognized this way
    #define RUNNING_POSIX
    #include <dlfcn.h>
#endif // defined

#if !defined(RUNNING_WIN) && !defined(RUNNING_POSIX)
    #error "Can not identify the platform"
#endif

#include <string>
#include <system_error>
#include <exception>

namespace kafe
{
    namespace abc
    {

        class DLLModule
        {
        private:
            typedef void(*FNDOSMTH)(void);
            typedef const char* (*FNGETNAME)(void);
            typedef long(*FNGETVERSION)(void);

#ifdef RUNNING_WIN
            HINSTANCE m_hInstance;
#endif // RUNNING_WIN
#ifdef RUNNING_POSIX
            void* m_hInstance;
#endif // RUNNING_POSIX
            std::string m_path;
            bool m_loaded;

        public:
            DLLModule();
            DLLModule(const std::string& path);
            ~DLLModule();

            void load(const std::string& path);
            void unload();

            FNDOSMTH doSomething;
            FNGETNAME getName;
            FNGETVERSION getVersion;
            FNGETVERSION requiredKafeAPI;
        };

    }  // namespace abc
}  // namespace kafe

#endif  // kafe_dll_loader

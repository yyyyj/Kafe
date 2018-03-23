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
    #define LOAD_MY_DLL(my_dll, path) if (NULL == (my_dll = LoadLibrary(path))) \
            { throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't load the library"); }
    #define LOAD_FCT_FROM_DLL_WITH_TYPE(proc_name, my_dll, type)  if (NULL == (proc_name = reinterpret_cast<type>(GetProcAddress(my_dll, #proc_name)))) \
            { throw std::system_error(std::error_code(::GetLastError(), std::system_category()), std::string("Couldn't find ") + #proc_name); }
#endif // defined

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) && defined(__MACH__)
    // linux, unix and apple systems should be recognized this way
    #define RUNNING_POSIX
    #include <dlfcn.h>
    #define LOAD_MY_DLL(my_dll, path) if (NULL == (my_dll = dlopen(path, RTLD_LAZY))) \
            { throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't load the library"); }
    #define LOAD_FCT_FROM_DLL_WITH_TYPE(proc_name, my_dll, type)  if (NULL == (proc_name = reinterpret_cast<type>(dlsym(my_dll, #proc_name)))) \
            { throw std::system_error(std::error_code(errno, std::system_category()), std::string("Couldn't find ") + #proc_name); }
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

            FNGETNAME getName;
            FNGETVERSION getVersion;
            FNGETVERSION requiredKafeAPI;
        };

    }  // namespace abc
}  // namespace kafe

#endif  // kafe_dll_loader

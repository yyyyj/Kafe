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

#ifndef kafe_plugins_base
#define kafe_plugins_base

#include <kafe/constants.hpp>

#ifdef RUNNING_WIN
    #include <windows.h>
    #define KAFE_PLUGIN_ENTRY_POINT BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved) { return TRUE; }
#endif // RUNNING_WIN

#ifdef RUNNING_POSIX
    // linux, unix and apple systems should be recognized this way
    #define KAFE_PLUGIN_ENTRY_POINT
#endif // RUNNING_POSIX

#define KAFE_EXPORT extern "C" __declspec(dllexport)

namespace kafe
{
    
    namespace plugin
    {
        
        ///
        
    }  // namespace plugin
    
}  // namespace kafe

#endif  // kafe_plugins_base
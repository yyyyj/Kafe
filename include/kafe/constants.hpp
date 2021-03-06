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

#ifndef kafe_cst
#define kafe_cst

// platform (useful for some functions)
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define RUNNING_WIN
#endif
#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) && defined(__MACH__)
    // linux, unix and apple systems should be recognized this way
    #define RUNNING_POSIX
#endif

#define KAFE_MAJOR_API_VERSION 1
#define KAFE_MINOR_API_VERSION 0
#define KAFE_PATCH_API_VERSION 0
#define KAFE_API_VERSION ((KAFE_MAJOR_API_VERSION << 16) | (KAFE_MINOR_API_VERSION << 8) | (KAFE_PATCH_API_VERSION))

#endif // kafe_cst

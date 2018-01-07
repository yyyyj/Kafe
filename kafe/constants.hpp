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

#endif // kafe_cst

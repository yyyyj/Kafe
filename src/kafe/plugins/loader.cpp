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

#include <kafe/plugins/loader.hpp>
#include <sstream>
#include <iomanip>

namespace kafe
{
    namespace abc
    {

        DLLModule::DLLModule() :
            m_hInstance(NULL)
            , m_path("")
            , m_loaded(false)
            , doSomething(NULL)
            , getName(NULL)
            , getVersion(NULL)
            , requiredKafeAPI(NULL)
        {}

        DLLModule::DLLModule(const std::string& path) :
            m_hInstance(NULL)
            , m_path(path)
            , m_loaded(false)
            , doSomething(NULL)
            , getName(NULL)
            , getVersion(NULL)
            , requiredKafeAPI(NULL)
        {
            load(m_path);
        }

        DLLModule::~DLLModule()
        {
            unload();
        }

        void DLLModule::load(const std::string& path)
        {
            if (m_loaded)
                unload();
            m_path = path;

#ifdef RUNNING_WIN
            if (NULL == (m_hInstance = LoadLibrary(m_path.c_str())))
                throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't load the library");

            if (NULL == (doSomething = reinterpret_cast<FNDOSMTH>(GetProcAddress(m_hInstance, "doSomething"))))
                throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't find doSomething");
            if (NULL == (getName = reinterpret_cast<FNGETNAME>(GetProcAddress(m_hInstance, "getName"))))
                throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't find getName");
            if (NULL == (getVersion = reinterpret_cast<FNGETVERSION>(GetProcAddress(m_hInstance, "getVersion"))))
                throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't find getVersion");
            if (NULL == (requiredKafeAPI = reinterpret_cast<FNGETVERSION>(GetProcAddress(m_hInstance, "requiredKafeAPI"))))
                throw std::system_error(std::error_code(::GetLastError(), std::system_category()), "Couldn't find requiredKafeAPI");
#endif // RUNNING_WIN

#ifdef RUNNING_POSIX
            if (NULL == (m_hInstance = dlopen(m_path.c_str(), RTLD_LAZY)))
                throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't load the library");

            if (NULL == (doSomething = reinterpret_cast<FNDOSMTH>(dlsym(m_hInstance, "doSomething"))))
                throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't find doSomething");
            if (NULL == (getName = reinterpret_cast<FNGETNAME>(dlsym(m_hInstance, "getName"))))
                throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't find getName");
            if (NULL == (getVersion = reinterpret_cast<FNGETVERSION>(dlsym(m_hInstance, "getVersion"))))
                throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't find getVersion");
            if (NULL == (requiredKafeAPI = reinterpret_cast<FNGETVERSION>(dlsym(m_hInstance, "requiredKafeAPI"))))
                throw std::system_error(std::error_code(errno, std::system_category()), "Couldn't find requiredKafeAPI");
#endif // RUNNING_POSIX

            m_loaded = true;
        }

        void DLLModule::unload()
        {
            if (m_loaded)
            {
#ifdef RUNNING_WIN
                FreeLibrary(m_hInstance);
#endif // RUNNING_WIN

#ifdef RUNNING_POSIX
                dlclose(m_hInstance);
#endif // RUNNING_POSIX
            }
        }

    }  // namespace abc
}  // namespace kafe

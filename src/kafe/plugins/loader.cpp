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
            
            LOAD_MY_DLL(m_hInstance, m_path.c_str())
            
            LOAD_FCT_FROM_DLL_WITH_TYPE(getName, m_hInstance, FNGETNAME)
            LOAD_FCT_FROM_DLL_WITH_TYPE(getVersion, m_hInstance, FNGETVERSION)
            LOAD_FCT_FROM_DLL_WITH_TYPE(requiredKafeAPI, m_hInstance, FNGETVERSION)

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

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

#ifndef kafe_utils
#define kafe_utils

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <exception>
#include <stdexcept>

#ifdef _MSC_VER
    // if compiling with visual studio, disable those warnings
    #pragma warning (disable: 4715)  // a function isn't returning a value
    #pragma warning (disable: 4244)  // conversion from addr_t to int, possible loss of data
    #pragma warning (disable: 4334)  // shift result of 32 bits implicitly converted in 64 bits
#endif

namespace kafe
{
    namespace abc
    {

        template <typename T>
        T abs(T value)
        {
            return (value >= 0) ? value : -value;
        }

        template <typename T>
        T setSign(T value, int bytesCount)
        {
            T msb = 1 << (8 * bytesCount - 1);
            if (sizeof(T) > (unsigned) bytesCount && (value & msb))
                { return msb - value; }
            return value;
        }

        template<typename T>
        T pop(std::vector<T>& obj, const int i)
        {
            if ((i == -1 || unsigned(i) == obj.size() - 1) && !!obj.size())
            {
                T e = obj[obj.size() - 1];
                obj.pop_back();
                return e;
            }
            if (0 <= i && unsigned(i) < obj.size())
            {
                T e = obj[i];
                obj.erase(obj.begin() + i);
                return e;
            }
            if (i < 0 && unsigned(-i) <= obj.size())
            {
                T e = obj[obj.size() + i];
                obj.erase(obj.begin() + obj.size() + i);
                return e;
            }
            throw std::runtime_error("Could not pop wanted element from vector");
        }

        template<typename T>
        void popNoReturn(std::vector<T>& obj, int i)
        {
            if (0 <= i && unsigned(i) < obj.size())
                obj.erase(obj.begin() + i);
            else if (i < 0 && unsigned(-i) <= obj.size())
                obj.erase(obj.begin() + obj.size() + i);
        }

        std::string hexstr(const unsigned& n);

        template<typename T>
        std::string str(const T& n)
        {
            std::ostringstream stm;
            stm << n;
            return stm.str();
        }

        template<typename T>
        T strTo(const std::string& v)
        {
            T t; std::stringstream b(v);
            b >> t;
            return t;
        }

        inline bool checkIfFileExists(const std::string& name)
        {
            std::ifstream f(name.c_str());
            return f.good();
        }

        inline unsigned long createVersionNumber(unsigned char major, unsigned char minor, unsigned char patch)
        {
            return ((int)major << 16) | ((int)minor << 8) | (patch);
        }

        inline std::string beautifyVersionNumber(unsigned long version)
        {
            int major = (version & (255 << 16)) >> 16
                , minor = (version & (255 << 8)) >> 8
                , patch = version & 255;

            return str<int>(major) + "." + str<int>(minor) + "." + str<int>(patch);
        }

    }  // namespace abc
}  // namespace kafe

#endif // kafe_utils

#ifndef kafe_utils
#define kafe_utils

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

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
        T pop(std::vector<T>& obj, int i)
        {
            T element {};

            if (0 <= i && (unsigned)i < obj.size())
            {
                element = obj[i];
                obj.erase(obj.begin() + i);
            }
            else if (i < 0 && (unsigned)(-i) <= obj.size())
            {
                element = obj[obj.size() + i];
                obj.erase(obj.begin() + obj.size() + i);
            }

            return element;
        }

        template<typename T>
        void popNoReturn(std::vector<T>& obj, int i)
        {
            if (0 <= i && (unsigned)i < obj.size())
                obj.erase(obj.begin() + i);
            else if (i < 0 && (unsigned)(-i) <= obj.size())
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

        inline int createVersionNumber(unsigned char major, unsigned char minor, unsigned char patch)
        {
            return ((int)major << 16) | ((int)minor << 8) | (patch);
        }

    }  // namespace abc
}  // namespace kafe

#endif // kafe_utils

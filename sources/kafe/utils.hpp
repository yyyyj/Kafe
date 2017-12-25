#ifndef kafe_utils
#define kafe_utils

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace kafe
{
    namespace abc
    {

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
        void pop_no_return(std::vector<T>& obj, int i)
        {
            if (0 <= i && (unsigned)i < obj.size())
                obj.erase(obj.begin() + i);
            else if (i < 0 && (unsigned)(-i) <= obj.size())
                obj.erase(obj.begin() + obj.size() + i);
        }

        template<typename T>
        std::string str(const T& n)
        {
            std::ostringstream stm;
            stm << n;
            return stm.str();
        }

        template<typename T>
        T str_to(const std::string& v)
        {
            T t; std::stringstream b(v);
            b >> t;
            return t;
        }

        inline bool check_if_file_exists(const std::string& name)
        {
            std::ifstream f(name.c_str());
            return f.good();
        }

    }  // namespace abc
}  // namespace abc

#endif // kafe_utils

#include "tests.hpp"

std::string replaceAll(std::string str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return "";
    std::size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
    return str;
}

std::string format(int number, std::size_t sz)
{
    std::string text = kafe::abc::str(number);
    while (text.size() < sz)
        { text.insert(0, 1, ' '); }
    return text;
}

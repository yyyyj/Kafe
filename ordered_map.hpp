#ifndef kafe_ordered_map
#define kafe_ordered_map

#include <vector>
#include <string>

#include "value.hpp"
#include "utils.hpp"

namespace kafe
{

    class OrderedMap
    {
    private:
        std::vector<std::string> m_keys;
        std::vector<Value> m_values;
    };

}  // namespace kafe

#endif // kafe_ordered_map

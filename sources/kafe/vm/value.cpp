#include "value.hpp"

namespace kafe
{

    bool operator!=(const Value& a, const Value& b) { return !(a == b); }
    bool operator>=(const Value& a, const Value& b) { return !(a < b); }
    bool operator<=(const Value& a, const Value& b) { return (a < b) || (a == b); }
    bool operator>(const Value& a, const Value& b) { return (!(a == b)) && (!(a < b)); }

}  // namespace kafe

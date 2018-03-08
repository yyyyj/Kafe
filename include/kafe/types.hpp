#ifndef kafe_types
#define kafe_types

#include <vector>
#include <cstdint>
#include <string>

namespace kafe
{

    typedef unsigned char       inst_t;
    typedef std::vector<inst_t> bytecode_t;

    typedef int16_t      micro_int_t;
    typedef uint16_t     micro_uint_t;
    typedef int32_t      smol_int_t;
    typedef uint32_t     smol_uint_t;
    typedef int64_t      int_t;
    typedef uint64_t     uint_t;
    typedef std::size_t  addr_t;
    typedef std::string  str_t;

}  // namespace kafe

#endif // kafe_types

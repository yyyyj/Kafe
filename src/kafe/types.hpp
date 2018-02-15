#ifndef kafe_bytecode
#define kafe_bytecode

#include <vector>
#include <cstdint>

namespace kafe
{

    typedef unsigned char       inst_t;
    typedef std::vector<inst_t> bytecode_t;

    // fixed data types
    typedef int16_t             int2B_t;
    typedef uint16_t            uint2B_t;
    typedef int32_t             int4B_t;
    typedef uint32_t            uint4B_t;
    typedef int64_t             int8B_t;
    typedef uint64_t            uint8B_t;
    typedef int64_t             addr_t;

}  // namespace kafe

#endif // kafe_bytecode

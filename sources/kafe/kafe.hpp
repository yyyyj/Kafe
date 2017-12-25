#ifndef kafe_kafe
#define kafe_kafe

#include "vm/vm.hpp"
#include "lexer/lexer.hpp"
#include "utils.hpp"
#include "types.hpp"

#include <string>

namespace kafe
{

    void runString(const std::string& code);
    void execFile(const std::string& filename);

}  // namespace kafe

#endif // kafe_kafe

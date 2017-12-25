#include "kafe.hpp"

namespace kafe
{

    void runString(const std::string& code)
    {
        Lexer lexer(code);
        Parser parser(lexer);
        parser.composeAST();
        VM vm;
        vm.exec(parser.generateBytecode());
    }

    void execFile(const std::string& code)
    {
        // read the file
        std::string filecontent = "";

        runString(filecontent);
    }

}  // namespace kafe

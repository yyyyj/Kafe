#include "parser.hpp"

namespace kafe
{

    /*namespace internal
    {

        std::string exec(const char* cmd)
        {
            std::array<char, 128> buffer;
            std::string result;
            std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
            if (!pipe)
                { throw std::runtime_error("popen() failed!"); }
            while (!feof(pipe.get()))
            {
                if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
                    { result += buffer.data(); }
            }
            return result;
        }

        std::string execScript(const std::string& cmd)
        {
            return exec((std::string(pythonCMD) + " " + cmd).c_str());
        }

    }  // namespace internal
    */

    void generateBytecode(const std::vector<std::string>& files, const std::string& output_fn, bool optimize, bool ast)
    {
        /*std::string command = "parser/generateBytecode.py ";
        for (std::size_t i=0; i < files.size(); ++i)
        {
            command += files[i] + " ";
        }
        command += std::string("--out ") + output_fn;
        command += (optimize ? std::string(" -O") : std::string(""));
        command += (ast ? std::string(" --ast") : std::string(""));

        internal::execScript(command);*/
    }

    void testANTLR()
    {
        std::string line;
        std::ifstream kafeFile("examples/plaintext/all_kw_test.kafe");
        if (kafeFile.is_open())
        {
            std::cout << "file found" << std::endl;
            antlr4::ANTLRInputStream input(kafeFile);
            KafeLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            tokens.fill();
            for (auto token : tokens.getTokens())
            {
                std::cout << token->toString() << std::endl;
            }
            KafeParser parser(&tokens);
            antlr4::tree::ParseTree* tree = parser.chunk();
            std::cout << tree->toStringTree(&parser) << std::endl;
            kafeFile.close();
        }
        /*else
            { throw std::runtime_error("Could not open wanted file"); }*/
    }

}  // namespace kafe

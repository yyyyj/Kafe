#include "parser.hpp"

namespace kafe
{

    namespace internal
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

    void generateAndSaveAST(const std::string& filename)
    {
        internal::execScript("parser/generateAST.py " + filename + " --save");
    }

    void generateBytecode(const std::string& filename)
    {
        internal::execScript("parser/generateBytecode.py " + filename);
    }

}  // namespace kafe

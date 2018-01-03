#ifndef kafe_lexer
#define kafe_lexer

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

#include "tokens.hpp"

namespace kafe
{

    class Lexer
    {
    private:
        const std::vector<std::string> m_regexs_to_string = {
            std::string("^(\\+|-|\\*|/|%|<=|>=|!=|<<|>>|&&|\\|\\||&|\\||~|!|<|>|==|\\^)"),
            std::string("^(((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?|\"[^\"]*\"|true|false)"),
            std::string("^[a-zA-Z0-9@_\\?]+"),
            std::string("^\\s{1}"), std::string("^#.*"),

            std::string("^struct"), std::string("^fun"), std::string("^ret"), std::string("^end"),
            std::string("^dyn"), std::string("^="),
            std::string("^for"), std::string("^while"), std::string("^if"),
            std::string("^in"),
            std::string("^\\."), std::string("^:"), std::string("^--"),
        };
        const std::size_t m_ops_pos        = 0
                        , m_id_pos         = 2
                        , m_value_pos      = 1
                        , m_whitespace_pos = 3
                        , m_comment_pos    = 4;
        std::string m_code;

        KafeTokenType getTypeFromStringTok(const std::string& token, const std::string& reg);

    public:
        static const KafeToken EndOfFile;

        Lexer(const std::string& code);
        ~Lexer();

        KafeToken getNextToken();
    };

}  // namespace kafe

#endif // kafe_lexer

#include "lexer.hpp"

namespace kafe
{

    const KafeToken Lexer::EndOfFile = KafeToken(KafeTokenType::EndOfFile, "EOF");

    Lexer::Lexer(const std::string& code) :
        m_code(code)
    {}

    Lexer::~Lexer() {}

    KafeTokenType Lexer::getTypeFromStringTok(const std::string& token, const std::string& reg)
    {
        // handling keywords and specials characters (--, ., :)
        for (auto& pair_ : pairs_toktype_str)
        {
            if (token == pair_.value)
                return pair_.type;
        }

        // handling operator, id, value, whitespace, and comment
        if (reg == m_regexs_to_string[m_ops_pos])
            return KafeTokenType::Operator;
        else if (reg == m_regexs_to_string[m_id_pos])
            return KafeTokenType::Identifier;
        else if (reg == m_regexs_to_string[m_value_pos])
            return KafeTokenType::Value;
        else if (reg == m_regexs_to_string[m_whitespace_pos])
            return KafeTokenType::Whitespace;
        else if (reg == m_regexs_to_string[m_comment_pos])
            return KafeTokenType::Comment;

        return KafeTokenType::UnknownToken;
    }

    KafeToken Lexer::getNextToken()
    {
        // if the file is empty return the EOF token
        if (m_code.empty())
            return Lexer::EndOfFile;

        for (auto reg : m_regexs_to_string)
        {
            std::smatch m;
            if (std::regex_search(m_code, m, std::regex(reg)))
            {
                std::string match0(m[0]);
                // remove the match form the string
                m_code = std::regex_replace(m_code, std::regex(reg), std::string(""), std::regex_constants::format_first_only);
                KafeTokenType type = getTypeFromStringTok(match0, reg);
                return KafeToken(type, match0);
            }
        }
        // if we are here it means we did not return anything
        throw std::runtime_error("Can not identify next token");
    }

}  // namespace kafe

#include "tokens.hpp"

namespace kafe
{

    const std::vector<PairTokenType_Str> pairs_toktype_str = {
        {KafeTokenType::Structure, "struct"},
        {KafeTokenType::Function, "fun"},
        {KafeTokenType::Return, "ret"},
        {KafeTokenType::End, "end"},

        {KafeTokenType::Dynamic, "dyn"},
        {KafeTokenType::Assign, "="},

        {KafeTokenType::For, "for"},
        {KafeTokenType::While, "while"},
        {KafeTokenType::If, "if"},

        {KafeTokenType::In, "in"},

        {KafeTokenType::AttributeAccessor, "."},
        {KafeTokenType::TypeDeclarator, ":"},
        {KafeTokenType::ArgumentSeparator, "--"},

        {KafeTokenType::Operator, "operator"},

        {KafeTokenType::Identifier, "identifier"},
        {KafeTokenType::Value, "value"},

        {KafeTokenType::Whitespace, "whitespace"},
        {KafeTokenType::Comment, "comment"},

        {KafeTokenType::EndOfFile, "EOF"},
        {KafeTokenType::UnknownToken, "???"}
    };

    std::ostream& operator<<(std::ostream& os, KafeTokenType toktype)
    {
        for (auto pair_ : pairs_toktype_str)
        {
            if (pair_.type == toktype)
            {
                os << pair_.value;
                break;
            }
        }
        return os;
    }

    KafeToken::KafeToken(KafeTokenType t, const std::string& v) :
        m_type(t)
        , m_value(v)
    { }

    KafeToken::~KafeToken() {}

    KafeTokenType KafeToken::getType()
    {
        return m_type;
    }

    const std::string& KafeToken::getValue()
    {
        return m_value;
    }

    bool KafeToken::operator==(const KafeToken& other) const
    {
        return (m_type == other.m_type) && (m_value == other.m_value);
    }

    bool operator!=(const KafeToken& a, const KafeToken& b)
    {
        return !(a == b);
    }

}  // namespace kafe

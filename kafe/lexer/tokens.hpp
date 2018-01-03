#ifndef kafe_tokens
#define kafe_tokens

#include <regex>
#include <vector>
#include <string>
#include <iostream>

namespace kafe
{

    enum class KafeTokenType
    {
        Structure,
        Function,
        Return,
        End,

        Dynamic,
        Assign,

        For,
        While,
        If,

        In,

        AttributeAccessor,
        TypeDeclarator,
        ArgumentSeparator,

        Operator,

        Identifier,
        Value,

        Whitespace,
        Comment,

        EndOfFile,
        UnknownToken
    };
    std::ostream& operator<<(std::ostream& os, KafeTokenType toktype);

    struct PairTokenType_Str
    {
        KafeTokenType type;
        std::string value;
    };

    extern const std::vector<PairTokenType_Str> pairs_toktype_str;

    class KafeToken
    {
    private:
        KafeTokenType m_type;
        std::string m_value;

    public:
        KafeToken(KafeTokenType t, const std::string& v);
        ~KafeToken();

        KafeTokenType getType();
        const std::string& getValue();

        bool operator==(const KafeToken& other) const;
    };
    bool operator!=(const KafeToken& a, const KafeToken& b);

}  // namespace kafe

#endif // kafe_tokens

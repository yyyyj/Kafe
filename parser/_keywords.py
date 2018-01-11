# coding : utf-8

KEYWORDS = (
    "fun", "ret", "end",
    "while", "for",
    "if", "elif", "else",
    "dyn",
    "in",
)

SPECIALS = (
    ":",
    "--",
    ".",
    "[", "]",
    "(", ")"
)

LIST_DELIMITERS = ("[", "]")

DATA_TYPES = (
    "int",
    "double",
    "str",
    "bool",
    "list",
    "void"
)

BOOLEANS = ("true", "false")

STRING_DELIMITERS = ("\"", "'")

OPERATORS = (
    "+", "-", "*", "/", "%",
    "++", "--",
    "&", "|", "~", "<<", ">>", "^",
    "&&", "||", "!",
    "<", "<=", ">", ">=", "==", "!="
)

COMMENTS = ("#", )


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

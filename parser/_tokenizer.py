# coding : utf-8

from _keywords import *


class Token:
    def __init__(self, content, kind, pos):
        self.content = content
        self.kind = kind
        self.pos = pos


def isDigit(word):
    word = word.lower()

    if "." not in word and "e" not in word:
        return word.isdigit()
    else:
        int_part, floating_part = word.split(".")
        exponent = None
        if "e" in floating_part:
            floating_part, exponent = floating_part.split("e")
        return int_part.isdigit() and floating_part.isdigit() and \
            (exponent.isidigt() if isinstance(exponent, str) else True)


def guessKind(word):
    if word in DATA_TYPES:
        return "type"
    elif word in KEYWORDS:
        return "keyword"
    elif isDigit(word):
        return "number"
    elif isString(word):
        return "string"
    elif word in BOOLEANS:
        return "bool"
    elif word in SPECIALS:
        return "special"
    return "unknown"


def tokenize(content):
    tokens_list = []

    for line_nb, line_content in enumerate(content):
        tok = None
        in_string = False
        for char_nb, char in enumerate(line_content):
            if tok is None:
                tok = Token(char, "unknown", (char_nb, line_nb))
            else:
                if (char != " " and not in_string) or (in_string):
                    # we skip spaces if we aren't in a string declaration
                    # but we must add the spaces to the content of the token if we are in a str
                    tok.content += char
                elif char == " ":
                    tok.kind = guessKind(tok.content)
                    tokens_list.append(tok)
                    tok = None

    return tokens_list


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

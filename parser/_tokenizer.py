# coding : utf-8

from _keywords import *


def decl(f, name, value):
    if not hasattr(f, name):
        f.__dict__[name] = value


class TokenizingError(Exception):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)


class Token:
    def __init__(self, content, kind, pos):
        self.content = content
        self.kind = kind
        self.pos = pos

    def __str__(self):
        return "<Token `{}` {} {}>".format(self.content, self.kind, self.pos)

    def __repr__(self):
        return self.__str__()


def isDigit(word):
    word = word.lower()

    if "." not in word:
        return word.isdigit()
    else:
        int_part, floating_part = word.split(".")
        return int_part.isdigit() and floating_part.isdigit()


def isString(word):
    return word[0] == word[-1] and word[-1] in STRING_DELIMITERS


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
    return "id"


def tokenize(content):
    tokens_list = []

    for line_nb, line_content in enumerate(content):
        tok = tok = Token("", "unknown", (0, line_nb))
        in_string = False
        if tokenize.debug: print(line_content, "\n")
        for char_nb, char in enumerate(line_content):
            if tok.content == "":
                tok.pos = (char_nb, line_nb)

            if char in STRING_DELIMITERS:
                # first we check if we are in a string
                in_string = not in_string
                tok.content += char
                if tokenize.debug: print("string delimiter found `{}`".format(char))
            elif in_string:
                if tokenize.debug: print("in string, adding a char `{}`".format(char))
                tok.content += char
            elif not in_string and (tok.content + char in SPECIALS or char in SPECIALS):
                if char not in SPECIALS:
                    tok.content += char
                    tok.kind = guessKind(tok.content)
                    tokens_list.append(tok)
                    tok = Token("", "unknown", (char_nb, line_nb))
                else:
                    if tok.content:
                        tok.kind = guessKind(tok.content)
                        tokens_list.append(tok)
                    tok = Token(char, guessKind(char), (char_nb, line_nb))
                    tokens_list.append(tok)
                    tok = Token("", "unknown", (char_nb, line_nb))
                    pass
                if tokenize.debug: print("found special token `{}`".format(tokens_list[-1].content))
            elif not in_string and char != " ":
                tok.content += char
                if tokenize.debug: print("not in string, adding a char `{}`".format(char))
            elif not in_string and char == " " and tok.content:
                tok.kind = guessKind(tok.content)
                tokens_list.append(tok)
                tok = Token("", "unknown", (char_nb, line_nb))
                if tokenize.debug: print("found new token")
                continue
            else:
                pass
                if tokenize.debug: print("what kind of thing is this : `{}`".format(char))
        if tok.content:
            tok.kind = guessKind(tok.content)
            tokens_list.append(tok)

    if in_string:
        raise TokenizingError("Unterminated string")

    return tokens_list


decl(tokenize, "debug", False)


if __name__ == '__main__':
    import _examples as kafeExamples
    tokenize.debug = True
    for tok in tokenize(kafeExamples.EVERY_KW_EX):
        print(tok)

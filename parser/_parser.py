# coding : utf-8

import _ast as kafeAST
import _tokenizer as kafeTokenizer
from _keywords import *


class Parser:
    def __init__(self, filename=None, file_content=None):
        self.program = kafeAST.AST()
        self.file_content = open(filename).readlines() if filename is not None else file_content
        assert self.file_content is not None, "Need either a filename or a file content"
        self.tokens = None
        self.token_pointer = 0
        self.errors = []

    def addError(self, message, pos):
        self.errors.insert(0, (message, pos))

    def tokenize(self):
        # call the tokenizer
        self.tokens = kafeTokenizer.tokenize(self.file_content)

    def optimizeBytecode(self):
        # currently doing nothing
        # should optimize things such as `dyn a : int = 5 + 7` as `dyn a : int = 12`
        for node in self.program:
            node.optimize()

    def saveBytecode(self, filename):
        with open(filename, "wb") as file:
            file.write(self.program.getBytecode())

    def jumpToEndOfAGroupOfBlocs(self):
        new_blocs = 1
        while new_blocs != 0:
            if self.tokens_list[self.token_pointer].content == "end":
                new_blocs -= 1
            if self.tokens_list[self.token_pointer].content in BLOC_OPENING:
                new_blocs += 1
            self.token_pointer += 1

    def parseMatching(self, keyword=None):
        assert keyword.content != "" and keyword.content in KEYWORDS, \
                "Given keyword is unknown `{}`".format(keyword)

        if keyword == "fun":
            self.parseFunction()
        elif keyword == "struct":
            self.parseStructure()
        elif keyword == "dyn":
            self.parseVar()
        elif keyword == "if":
            self.parseIf()
        elif keyword == "while":
            self.parseWhile()
        elif keyword == "for":
            self.parseFor()
        else:
            self.addError("Can not parse block starting with `{}`".format(keyword), keyword.pos)
            self.jumpToEndOfAGroupOfBlocs()

    def parseStructure(self):
        pass

    def parseFunction(self):
        pass

    def parseValue(self):
        pass

    def parseVar(self):
        pass

    def parseCondition(self):
        pass

    def parseIf(self):
        pass

    def parseWhile(self):
        pass

    def parseFor(self):
        pass

    def parseFunctionCall(self):
        pass

    def parse(self):
        self.tokenize()

        while self.token_pointer < len(self.tokens_list):
            if self.tokens_list[self.token_pointer].kind == "keyword":
                self.parseMatching(keyword=self.tokens_list[self.token_pointer])

    def getRepr(self):
        return self.program.getRepr()


if __name__ == '__main__':
    import _examples as kafeExamples
    parser = Parser(file_content=kafeExamples.EVERY_KW_EX)

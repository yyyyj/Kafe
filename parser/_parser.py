# coding : utf-8

import _ast as kafeAST
from _keywords import *


class Parser:
    def __init__(self, filename):
        self.program = kafeAST.AST()
        self.file_content = open(filename).read()

    def optimizeBytecode(self):
        # currently doing nothing
        # should optimize things such as `dyn a : int = 5 + 7` as `dyn a : int = 12`
        pass

    def saveBytecode(self, filename):
        with open(filename, "wb") as file:
            file.write(self.program.getBytecode())

    def parse(self):
        pass

    def getRepr(self):
        return self.program.getRepr()


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

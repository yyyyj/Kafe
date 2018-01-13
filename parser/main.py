# coding : utf-8

import os, sys

import _parser as kafeParser


def parse(files):
    parser = kafeParser.Parser(files=files)
    parser.parse()
    return parser


def generateBytecode(parser, output, save_ast):
    parser.optimizeBytecode()
    parser.saveBytecode(output)
    if save_ast:
        with open(output + ".ast", "w") as file:
            file.write(parser.getRepr())


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

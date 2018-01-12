# coding : utf-8

import os, sys

import _parser as kafeParser


def parse(files):
    parser = kafeParser.Parser(files)
    parser.parse()
    return parser


def generateBytecode(parser, output=""):
    parser.optimizeBytecode()
    parser.saveBytecode(output)


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

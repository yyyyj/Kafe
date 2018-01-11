# coding : utf-8

import os, sys
import main as kafe


def main(argv):
    filename, save, output_fn = "", False, ".ast"
    if argv:
        filename = argv[0]
        if "--save" in argv:
            save = True
            output_fn = filename + output_fn

    if not filename:
        raise ValueError("Need a valid file to parse")

    ast = kafe.parse(filename)
    if save:
        with open(output_fn, "w") as file:
            file.write(ast.getRepr())
    else:
        print(ast.getRepr())

if __name__ == '__main__':
    main(sys.argv[1:])

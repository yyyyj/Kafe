# coding : utf-8

import os, sys
import main as kafe


def main(argv):
    fn, save, output_fn = "", False, ".ast"
    if argv:
        fn = argv[0]
        if "--save" in argv:
            save = True
            output_fn = fn + output_fn

    if not fn:
        raise ValueError("Need a valid file to parse")

    ast = kafe.parse(filename=fn)
    if save:
        with open(output_fn, "w") as file:
            file.write(ast.getRepr())
    else:
        print(ast.getRepr())

if __name__ == '__main__':
    main(sys.argv[1:])

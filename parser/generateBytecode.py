# coding : utf-8

import os, sys
import main as kafe


def main(argv):
    filename, output_fn = "", ""
    if argv:
        filename = argv[0]
        output_fn = filename.split(".")[0] + ".kfb"

    if not filename:
        raise ValueError("Need a valid file to parse")

    kafe.generateBytecode(kafe.parse(filename), output=output_fn)

if __name__ == '__main__':
    main(sys.argv[1:])

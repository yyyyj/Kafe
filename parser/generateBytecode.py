# coding : utf-8

import os, sys
import main as kafe


def main(argv):
    fn, output_fn = "", ""
    if argv:
        fn = argv[0]
        output_fn = fn.split(".")[0] + ".kfb"

    if not filename:
        raise ValueError("Need a valid file to parse")

    kafe.generateBytecode(kafe.parse(filename=fn), output=output_fn)

if __name__ == '__main__':
    main(sys.argv[1:])

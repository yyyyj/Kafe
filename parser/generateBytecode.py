# coding : utf-8

import os, sys
import main as kafe


def main(argv):
    f, output_fn = [], ""
    assert argv
    if argv:
        assert "--out" in argv and len(argv) > argv.index("--out") + 1
        output_fn = argv[argv.index("--out") + 1]
        for c in argv:
            if c == "--out":
                break
            f.append(c)

    if not filename:
        raise ValueError("Need a valid file to parse")

    kafe.generateBytecode(kafe.parse(files=f), output=output_fn)

if __name__ == '__main__':
    main(sys.argv[1:])

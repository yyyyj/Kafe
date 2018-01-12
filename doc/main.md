# Documentation
*Official documentation for the programming language Kafe*

[Installing](installing.md)

[Building the project](building.md)

[How the VM works](vm.md)

[Code examples](examples.md)

# Command line options for the Kafe VM

The VM is designed to read and execute bytecode, but it can also turn your kafe code into bytecode.

```bash
/kafe-master/$ kafe -h
SYNOPSIS
        /kafe-master/kafe [-f <Input bytecode>] [-c <Input file>] [--ast <Input file => AST>] [-d <Debug mode>] [--tests] [-h]

OPTIONS
        <Input bytecode>
                    Input bytecode file to execute

        <Input file>
                    Input source code file to compile into bytecode

        <Input file => AST>
                    Generate the AST of the given kafe source code file and save it to SOURCE.ast

        <Debug mode>
                    Debug mode for the VM

        --tests     Start all the tests
        -h, --help  Display help
```

The options `-f`, `-c`, `--ast` and `-d` can be cumulated, but the options `-h` and `--tests` terminate the program when they are done.

In the background, the options `-c` and `--ast` are short cuts for those two commands :

`python parser/generateBytecode.py [filename]` and `python parser/generateAST.py [filename] --save`

(depending on your system, it's either `python` or `python3` which will be used to run the scripts)

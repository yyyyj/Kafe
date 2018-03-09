# Documentation
*Official documentation for the programming language Kafe*

[Installing](installing.md)

[Building the project](building.md)

[How the VM works](vm.md)

[How to create plugins for the VM](plugins.md)

[Language documentation](lang/main.md)

[Code examples](examples.md)

# Command line options for the Kafe VM

The VM is designed to read and execute bytecode, but it can also turn your Kafe code into bytecode, parsing it using ANTLR4.

```bash
/kafe-master/$ kafe help
Usage:
        kafe help
        kafe build <file>... -o <outfile> [-a]
        kafe ((exec <file>) | tests) [-d] [-i]
        kafe --version
Options:
        -a, --ast                   Save the generated AST to <outfile>.ast
        -d, --debug                 Enable debug mode
        -i, --interactive           Start a CLI to be able to execute a file instruction per instruction
        --version                   Display version number
LICENSE
        Mozilla Public License 2.0
```

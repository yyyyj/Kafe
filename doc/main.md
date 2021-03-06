# Documentation
*Official documentation for the programming language Kafe*

[Installing](installing.md)

[Building the project](building.md)

[How the VM works](vm.md)

[How to create plugins for the VM](plugins.md)

[How to use setup a project to use Kafe as a scripting language](setup-as-scripting.md)

[Language documentation](lang/main.md)

[Code examples](examples.md)

# Command line options for the Kafe VM

The VM is designed to read and execute bytecode, but it can also turn your Kafe code into bytecode, parsing it using ANTLR4.

```bash
/kafe-master/$ kafe --help
SYNOPSIS
        /kafe-master/kafe --help
        /kafe-master/kafe build <file>... -o <outfile> [-a]
        /kafe-master/kafe ((exec <file>) | tests) [-d] [-i] [-E]
        /kafe-master/kafe --version

OPTIONS
        -a, --ast                   Save the generated AST to <file>.ast
        -d, --debug                 Enable debug mode
        -i, --interactive           Start a CLI to be able to execute a file instruction per instruction
        -E, --experimental          Enable experimental features
        --version                   Display version number

LICENSE
        Mozilla Public License 2.0
```

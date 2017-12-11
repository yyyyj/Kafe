#include <iostream>
#include <string>

#include "vm.hpp"
#include "utils.hpp"

std::string format(int number, std::size_t sz)
{
    std::string text = vm::abc::str(number);
    while (text.size() < sz)
        { text.insert(0, 1, ' '); }
    return text;
}

void start(const std::string& test_name, char* bytecode, unsigned bytecode_size)
{
    vm::VM vm;
    vm.setDebug(true);

    std::cout << "[ " << test_name << " ]" << std::endl << std::endl;

    std::cout << " pos  | code " << std::endl
              << "------|------" << std::endl;
    for (unsigned i=0; i < bytecode_size; ++i)
        std::cout << format((unsigned) i, 4) << "  |  "
                  << format((unsigned) bytecode[i], 4) << std::endl;
    std::cout << std::endl;

    std::cout << "Calling order" << std::endl
              << "-------------" << std::endl;
    vm.exec(bytecode, bytecode_size);
    std::cout << std::endl
              << "Stack" << std::endl
              << "-------------" << std::endl
              << "Size : " << vm.getStack().size()
              << std::endl << std::endl;

    for (std::size_t _i=vm.getStack().size(); _i > 0; --_i)
    {
        int i = _i - 1;;
        std::cout << "[" << i << "] ";
        if (vm.getStack()[i].type == vm::TYPE_INT)
            std::cout << "INT " << vm.getStack()[i].intValue;
        else if (vm.getStack()[i].type == vm::TYPE_BOOL)
            std::cout << "BOOL " << vm.getStack()[i].boolValue;
        else if (vm.getStack()[i].type == vm::TYPE_STRING)
            std::cout << "STRING " << vm.getStack()[i].stringValue;
        std::cout << std::endl;
    }
    std::cout << std::endl << "=================================" << std::endl << std::endl;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        // testing area

        // int:18768, str:hello, bool:true
        char bytecode[] = {
            vm::INST_INT, 0x49, 0x50,
            vm::INST_STR, 0x00, 0x05, 'h', 'e', 'l', 'l', 'o',
            vm::INST_BOOL, 'A',
            0x00
        };
        start("int:18768, str:hello, bool:true", bytecode, 14);

        // put the integer 1 into `var`, then put `var` at the top of the stack
        // then push the int 9 on the stack and perform an addition, push the result on the stack
        char bytecode2[] = {
            vm::INST_INT, 0x00, 0x01,
            vm::INST_VAR, 0x03, 'v', 'a', 'r',
            vm::INST_STORE_VAR,
            vm::INST_PUSH_VAR, 0x03, 'v', 'a', 'r',
            vm::INST_INT, 0x00, 0x09,
            vm::INST_PROCEDURE, vm::INST_ADD,
            0x00
        };
        start("var = 1; push(var); push(9); add", bytecode2, 19);

        // jump to the beginning ... until the world burns out in flame
        char bytecode3[] = {
            vm::INST_SEGMENT, 0x05, 'l', 'a', 'b', 'e', 'l',
            vm::INST_JUMP, 0x05, 'l', 'a', 'b', 'e', 'l',
            0x00
        };
        /// start("jump to `label` until the world burns", bytecode3, 15);

        char bytecode4[] = {
            vm::INST_DECL_SEG, 0x03, 'v', 'a', 'r', 0x00, 0x14,  // len:6
            vm::INST_BOOL, 0x00,                                 // len:2 => 8
            vm::INST_VAR, 0x01, 'a',                             // len:3 => 11
            vm::INST_STORE_VAR,                                  // len:1 => 12
            vm::INST_SEGMENT, 0x03, 'v', 'a', 'r', 0x00, 0x08,
                vm::INST_PUSH_VAR, 0x01, 'a',
                vm::INST_BOOL, 0x01,
                vm::INST_PROCEDURE, vm::INST_NE,
                vm::INST_RET,
            vm::INST_JUMP, 0x03, 'v', 'a', 'r',
            0x00

        };
        start("testing segments, jump and ret", bytecode4, 33);
    }

    return 0;
}

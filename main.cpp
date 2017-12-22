#include <iostream>
#include <string>

#include "vm.hpp"
#include "utils.hpp"

std::string format(int number, std::size_t sz)
{
    std::string text = kafe::abc::str(number);
    while (text.size() < sz)
        { text.insert(0, 1, ' '); }
    return text;
}

void start(const std::string& test_name, kafe::bytecode_t bytecode)
{
    kafe::VM vm;
    vm.setDebug(true);

    std::cout << "[ " << test_name << " ]" << std::endl << std::endl;

    std::cout << " pos  | code " << std::endl
              << "------|------" << std::endl;
    for (std::size_t i=0; i < bytecode.size(); ++i)
        std::cout << format((unsigned) i, 4) << "  |  "
                  << format((unsigned) bytecode[i], 4) << std::endl;
    std::cout << std::endl;

    std::cout << "Calling order" << std::endl
              << "-------------" << std::endl;
    vm.exec(bytecode);
    std::cout << std::endl << std::endl
              << "Stack"   << std::endl
              << "-------------" << std::endl
              << "Size : " << vm.getStack().size()
              << std::endl << std::endl;

    for (std::size_t _i=vm.getStack().size(); _i > 0; --_i)
    {
        int i = _i - 1;
        std::cout << "[" << i << "] ";
        if (vm.getStack()[i].type == kafe::TYPE_INT)
            std::cout << "INT " << vm.getStack()[i].intValue;
        else if (vm.getStack()[i].type == kafe::TYPE_BOOL)
            std::cout << "BOOL " << vm.getStack()[i].boolValue;
        else if (vm.getStack()[i].type == kafe::TYPE_STRING)
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
        kafe::bytecode_t bytecode1 = {
            kafe::INST_INT_2B, 0x49, 0x50,
            kafe::INST_STR, 0x00, 0x05, 'h', 'e', 'l', 'l', 'o',
            kafe::INST_BOOL, 'A',
            0x00
        };
        start("int:18768, str:hello, bool:true", bytecode1);

        // put the integer 1 into `var`, then put `var` at the top of the stack
        // then push the int 9 on the stack and perform an addition, push the result on the stack
        kafe::bytecode_t bytecode2 = {
            kafe::INST_INT_2B, 0x00, 0x01,
            kafe::INST_VAR, 0x00, 0x03, 'v', 'a', 'r',
            kafe::INST_STORE_VAR,
            kafe::INST_LOAD_VAR, 0x00, 0x03, 'v', 'a', 'r',
            kafe::INST_INT_2B, 0x00, 0x09,
            kafe::INST_PROCEDURE, kafe::INST_ADD,
            0x00
        };
        start("var = 1; push(var); push(9); add", bytecode2);

        // jump to the beginning ... until the world burns out in flame
        /*
        kafe::bytecode_t bytecode3[] = {
            kafe::INST_SEGMENT, 0x00, 0x05, 'l', 'a', 'b', 'e', 'l',
            kafe::INST_JUMP, 0x00, 0x05, 'l', 'a', 'b', 'e', 'l',
            0x00
        };
        start("jump to `label` until the world burns", bytecode3);
        */

        kafe::bytecode_t bytecode4 = {
            kafe::INST_DECL_SEG, 0x00, 0x03, 'v', 'a', 'r', 0x00, 0x17, // len:8
            kafe::INST_BOOL, 0x00,                                      // len:2 => 10
            kafe::INST_VAR, 0x00, 0x01, 'a',                            // len:3 => 14
            kafe::INST_STORE_VAR,                                       // len:1 => 15
            kafe::INST_SEGMENT, 0x00, 0x03, 'v', 'a', 'r', 0x00, 0x09,  // len:8 => 23
                kafe::INST_LOAD_VAR, 0x00, 0x01, 'a',                   // len:4 => 27
                kafe::INST_BOOL, 0x01,                                  // len:2 => 29
                kafe::INST_PROCEDURE, kafe::INST_NE,                    // len:2 => 31
                kafe::INST_RET,                                         // len:1 => 32
            kafe::INST_JUMP, 0x00, 0x03, 'v', 'a', 'r',                 // len:6 => 38
            0x00                                                        // len:1 => 39
        };
        start("testing segments, jump and ret", bytecode4);

        kafe::bytecode_t bytecode5 = {
            kafe::INST_INT_2B, 0x1a, 0x8b,
            kafe::INST_VAR, 0x00, 0x01, 'h',
            kafe::INST_STORE_VAR,
            kafe::INST_LOAD_VAR, 0x00, 0x01, 'h',
            kafe::INST_DUP,
            0x00
        };
        start("testing variable duplication", bytecode5);
    }

    return 0;
}

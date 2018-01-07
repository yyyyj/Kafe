#include "tests.hpp"

#include <iostream>

#define TEST_VM(name, obj, mode) test_vm( name , #obj , obj , mode )

std::string replaceAll(std::string str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return "";
    std::size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
    return str;
}

std::string format(int number, std::size_t sz)
{
    std::string text = kafe::abc::str(number);
    while (text.size() < sz)
        { text.insert(0, 1, ' '); }
    return text;
}

void test_vm(const std::string& test_name, const std::string& filename, kafe::bytecode_t bytecode, int debug_mode)
{
    kafe::VM vm;
    vm.setMode(debug_mode);

    std::cout << "[ " << test_name << " ]" << std::endl << std::endl;

    std::cout << " pos  | code " << std::endl
              << "------|------" << std::endl;
    for (std::size_t i=0; i < bytecode.size(); ++i)
        std::cout << format((unsigned) i, 4) << "  |  "
                  << format((unsigned) bytecode[i], 4) << std::endl;
    std::cout << std::endl;

    std::cout << "Calling order" << std::endl
              << "-------------" << std::endl;
    vm.load(bytecode);
    vm.exec();
    std::cout << std::endl << std::endl
              << "Stack"   << std::endl
              << "-------------" << std::endl
              << "Size : " << vm.getStack().size()
              << std::endl << std::endl;

    for (std::size_t _i=vm.getStack().size(); _i > 0; --_i)
    {
        int i = _i - 1;
        std::cout << "[" << i << "] " << kafe::convertTypeToString(vm.getStack()[i].type) << " " << vm.getStack()[i] << std::endl;
    }
    std::cout << std::endl << "=================================" << std::endl << std::endl;

    vm.saveBytecode("examples/" + filename);
}

int start_tests(int debug_mode)
{
    // int:18768, str:hello, bool:true
    kafe::bytecode_t bytecode1 = {
        kafe::INST_INT_2B, 0x49, 0x50,
        kafe::INST_STR, 0x00, 0x05, 'h', 'e', 'l', 'l', 'o',
        kafe::INST_BOOL, 'A',
        0x00
    };
    TEST_VM("int:18768, str:hello, bool:true", bytecode1, debug_mode);

    // put the integer 1 into `var`, then put `var` at the top of the stack
    // then push the int 9 on the stack and perform an addition, push the result on the stack
    kafe::bytecode_t bytecode2 = {
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_VAR, 0x00, 0x03, 'v', 'a', 'r',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 0x00, 0x03, 'v', 'a', 'r',
        kafe::INST_INT_2B, 0x00, 0x09,
        kafe::INST_PROCEDURE, 0, kafe::INST_ADD,
        0x00
    };
    TEST_VM("var = 1; push(var); push(9); add", bytecode2, debug_mode);

    // jump to the beginning ... until the world burns out in flame
    /*
    kafe::bytecode_t bytecode3[] = {
        kafe::INST_SEGMENT, 0x00, 0x05, 'l', 'a', 'b', 'e', 'l',
        kafe::INST_JUMP, 0x00, 0x05, 'l', 'a', 'b', 'e', 'l',
        0x00
    };
    TEST_VM("jump to `label` until the world burns", bytecode3, debug_mode);
    */

    kafe::bytecode_t bytecode4 = {
        kafe::INST_DECL_SEG, 0x00, 0x03, 'v', 'a', 'r', 0x00, 0x17, // len:8
        kafe::INST_BOOL, 0x00,                                      // len:2 => 10
        kafe::INST_VAR, 0x00, 0x01, 'a',                            // len:3 => 14
        kafe::INST_STORE_VAR,                                       // len:1 => 15
        kafe::INST_SEGMENT, 0x00, 0x03, 'v', 'a', 'r', 0x00, 0x0a,  // len:8 => 23
            kafe::INST_LOAD_VAR, 0x00, 0x01, 'a',                   // len:4 => 27
            kafe::INST_BOOL, 0x01,                                  // len:2 => 29
            kafe::INST_PROCEDURE, 0, kafe::INST_NE,                 // len:3 => 32
            kafe::INST_RET,                                         // len:1 => 33
        kafe::INST_JUMP, 0x00, 0x03, 'v', 'a', 'r',                 // len:6 => 39
        0x00                                                        // len:1 => 40
    };
    /* equivalent :
    dyn a : bool = false
    fun var : void
        true != a  # pushed onto the stack, BUT IT SHOULDN'T BE !
        ret
    end
    var  # calling the function var
    */
    TEST_VM("testing segments, jump and ret", bytecode4, debug_mode);

    kafe::bytecode_t bytecode5 = {
        kafe::INST_INT_2B, 0b11111111, 0b11111111,
        kafe::INST_VAR, 0x00, 0x01, 'h',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 0x00, 0x01, 'h',
        kafe::INST_DUP,
        kafe::INST_INT_2B, 0b01111111, 0b11111111,
        0x00
    };
    TEST_VM("testing variable duplication and negatives numbers (-32767, 32767)", bytecode5, debug_mode);

    return 0;
}











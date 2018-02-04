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

    std::cerr << "[ " << test_name << " ]" << std::endl << std::endl;

    std::cerr << " pos  | code " << std::endl
              << "------|------" << std::endl;
    for (std::size_t i=0; i < bytecode.size(); ++i)
        std::cerr << format((unsigned) i, 4) << "  |  "
                  << kafe::abc::hexstr((unsigned) bytecode[i]) << std::endl;
    std::cerr << std::endl;

    std::cerr << "Calling order" << std::endl
              << "-------------" << std::endl;
    vm.load(bytecode);
    vm.exec();
    std::cerr << std::endl << std::endl
              << "Stack"   << std::endl
              << "-------------" << std::endl
              << "Size : " << vm.getStack().size()
              << std::endl << std::endl;

    for (std::size_t j=vm.getStack().size(); j > 0; --j)
    {
        int i = j - 1;
        std::cerr << "[" << i << "] " << kafe::convertTypeToString(vm.getStack()[i].type) << " " << vm.getStack()[i] << std::endl;
    }
    std::cerr << std::endl   << std::endl
              << "Variables" << std::endl
              << "-------------" << std::endl
              << "Size : " << vm.getVariables().size()
              << std::endl << std::endl;
    for (auto& element : vm.getVariables())
    {
        std::cerr << element.first << " = " << element.second << " (" << kafe::convertTypeToString(element.second.type) << ")" << std::endl;
    }

    std::cerr << std::endl << "=================================" << std::endl << std::endl;

    vm.saveBytecode("examples/bytecode/" + filename);
}

int start_tests(int debug_mode)
{
    // int:18768, str:hello, bool:true
    kafe::bytecode_t bytecode1 = {
        kafe::INST_INT_2B, 0x49, 0x50,
        kafe::INST_STR, 'h', 'e', 'l', 'l', 'o', '\0',
        kafe::INST_BOOL, 'A',
        0x00
    };
    TEST_VM("int:18768, str:hello, bool:true", bytecode1, debug_mode);

    // put the integer 1 into `var`, then put `var` at the top of the stack
    // then push the int 9 on the stack and perform an addition, push the result on the stack
    kafe::bytecode_t bytecode2 = {
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_INT_2B, 0x00, 0x09,
        kafe::INST_PROCEDURE, ((kafe::INST_ADD & 0xff00) >> 8), (kafe::INST_ADD & 0x00ff),
        0x00
    };
    TEST_VM("var = 1; push(var); push(9); add", bytecode2, debug_mode);

    // jumps
    kafe::bytecode_t bytecode3 = {
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0f,
        kafe::INST_BOOL, 0x01,
        kafe::INST_JUMP_IF,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0f,
        kafe::INST_JUMP_IFN,

        kafe::INST_HALT,

        // segment, jumping back
            kafe::INST_BOOL, 0x00,
            kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x08,
            kafe::INST_JUMP,

        0x00
    };
    TEST_VM("push true, jump if => 15, push false, jump => 7, jump if not, halt", bytecode3, debug_mode);

    kafe::bytecode_t bytecode4 = {
        kafe::INST_BOOL, 0x00,
        kafe::INST_VAR, 'a', '\0',
        kafe::INST_STORE_VAR,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0d,
        kafe::INST_CALL,
        kafe::INST_HALT,

        // segment
            kafe::INST_LOAD_VAR, 'a', '\0',
            kafe::INST_BOOL, 0x01,
            kafe::INST_PROCEDURE, ((kafe::INST_NE & 0xff00) >> 8), (kafe::INST_NE & 0x00ff),
            kafe::INST_RET,

        0x00
    };
    /* equivalent :
    dyn a : bool = false
    fun var : bool
        ret true != a
    end
    (var)  # calling the function var
    */
    TEST_VM("testing segments, jump and ret", bytecode4, debug_mode);

    kafe::bytecode_t bytecode5 = {
        kafe::INST_INT_2B, 0b10000000, 0b00000000,
        kafe::INST_VAR, 'h', '\0',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 'h', '\0',
        kafe::INST_DUP,
        kafe::INST_INT_2B, 0b01111111, 0b11111111,
        0x00
    };
    TEST_VM("testing variable duplication and negatives numbers (-32767, 32767)", bytecode5, debug_mode);

    return 0;
}











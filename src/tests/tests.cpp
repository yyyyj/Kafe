#include "tests.hpp"
#include <fola/benchmark.hpp>
#include <iostream>

#define TEST_VM(name, obj) test_vm( name , #obj , obj , debug_mode );

#define CALL_PROCEDURE(c) ((c & 0xff00) >> 8), (c & 0x00ff)

void test_vm(const std::string& test_name, const std::string& filename, kafe::bytecode_t bytecode, int debug_mode)
{
    kafe::VM vm;
    vm.setMode(debug_mode);

    std::cerr << "[ " << test_name << " ]" << std::endl << std::endl;

    BENCHMARK_F("loading", vm.load(bytecode), us)

    if (debug_mode & kafe::VM::FLAG_BASIC_DEBUG)
        std::cerr << std::endl << "Calling order" << std::endl << "-------------" << std::endl;

    vm.exec(); vm.setMode(0);

    BENCHMARK_MRSTATS("", vm.exec(), 500, us)
    BENCHMARK_F("saving", vm.saveBytecode("examples/bytecode/" + filename), ms)

    if (vm.getStack().size())
    {
        std::cerr << std::endl << "Stack (" << vm.getStack().size() << ")" << std::endl << "-------------" << std::endl;
        for (std::size_t j=vm.getStack().size(); j > 0; --j)
            std::cerr << "[" << j - 1 << "] " << kafe::convertTypeToString(vm.getStack()[j - 1].type) << " " << vm.getStack()[j - 1] << std::endl;
    }
    if (vm.getVariables().size())
    {
        std::cerr << std::endl   << std::endl << "Variables (" << vm.getVariables().size() << ")" << std::endl << "-------------" << std::endl;
        for (auto& element : vm.getVariables())
            std::cerr << element.first << " = " << element.second << " (" << kafe::convertTypeToString(element.second.type) << ")" << std::endl;
    }
    std::cerr << std::endl << "=================================" << std::endl << std::endl;
}

int start_tests(int debug_mode)
{
    // just displaying useful info
    std::cerr << "Sizeof(Value) = " << sizeof(kafe::Value) << "b" << std::endl << std::endl;

    // int:18768, str:hello, bool:true
    kafe::bytecode_t bytecode1 = {
        kafe::INST_INT_2B, 0x49, 0x50,
        kafe::INST_STR, 'h', 'e', 'l', 'l', 'o', '\0',
        kafe::INST_BOOL, 'A',
        0x00
    };
    TEST_VM("int:18768, str:hello, bool:true", bytecode1);

    // put the integer 1 into `var`, then put `var` at the top of the stack
    // then push the int 9 on the stack and perform an addition, push the result on the stack
    kafe::bytecode_t bytecode2 = {
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_INT_2B, 0x00, 0x09,
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
        0x00
    };
    TEST_VM("var = 1; push(var); push(9); add", bytecode2);

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
    TEST_VM("push true, jump if => 15, push false, jump => 7, jump if not, halt", bytecode3);

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
            kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_NE),
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
    TEST_VM("testing segments, jump and ret", bytecode4);

    kafe::bytecode_t bytecode5 = {
        kafe::INST_INT_2B, 0b10000000, 0b00000000,
        kafe::INST_VAR, 'h', '\0',
        kafe::INST_STORE_VAR,
        kafe::INST_LOAD_VAR, 'h', '\0',
        kafe::INST_DUP,
        kafe::INST_INT_2B, 0b01111111, 0b11111111,
        0x00
    };
    TEST_VM("testing variable duplication and negatives numbers (-32767, 32767)", bytecode5);

    kafe::bytecode_t bytecode6 = {
        // (fibonacci 40)
        kafe::INST_INT_2B, 0x00, 0x28,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0a,
        kafe::INST_CALL,

        kafe::INST_HALT,
        // func fibonacci : int -- n : int   -----> ADDR: 0x0a
            kafe::INST_VAR, 'n', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_INT_2B, 0x00, 0x00, // a = 0
            kafe::INST_VAR, 'a', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_INT_2B, 0x00, 0x01, // b = 1
            kafe::INST_VAR, 'b', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_INT_2B, 0x00, 0x00,  // i = 0
            kafe::INST_VAR, 'i', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_LOAD_VAR, 'a', '\0',  // c = a   <-------------- 0x23
            kafe::INST_VAR, 'c', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_LOAD_VAR, 'b', '\0',  // a = b
            kafe::INST_VAR, 'a', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_LOAD_VAR, 'b', '\0',  // b = b + c
            kafe::INST_LOAD_VAR, 'c', '\0',
            kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
            kafe::INST_VAR, 'b', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_LOAD_VAR, 'i', '\0',  // i = i + 1
            kafe::INST_INT_2B, 0x00, 0x01,
            kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
            kafe::INST_VAR, 'i', '\0',
            kafe::INST_STORE_VAR,

            kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x23,

            kafe::INST_LOAD_VAR, 'i', '\0',  // if i == n then
            kafe::INST_LOAD_VAR, 'n', '\0',
            kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_NE),

            kafe::INST_JUMP_IF,  // jump to the beginning

            kafe::INST_LOAD_VAR, 'a', '\0',  // ret a

            kafe::INST_DEL_VAR, 'a', '\0',
            kafe::INST_DEL_VAR, 'b', '\0',
            kafe::INST_DEL_VAR, 'c', '\0',
            kafe::INST_DEL_VAR, 'i', '\0',
            kafe::INST_DEL_VAR, 'n', '\0',

            kafe::INST_RET,
        0x00
    };
    TEST_VM("Fibonacci", bytecode6);

    return 0;
}











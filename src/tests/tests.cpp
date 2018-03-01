#include "tests.hpp"
#include <fola/benchmark.hpp>
#include <iostream>

#define CALL_PROCEDURE(c) ((c & 0xff00) >> 8), (c & 0x00ff)

static int passed_tests = 0;
static int tests_count = 0;
static int debug_mode = kafe::VM::FLAG_DEFAULT_MODE;

void test_vm(const std::string& test_name, const std::string& filename, kafe::bytecode_t bytecode)
{
    tests_count++;

    kafe::VM vm;
    vm.setMode(debug_mode);
    vm.load(bytecode);

    std::cerr << "[ " << test_name << " ]" << std::endl << std::endl;
    if (debug_mode & kafe::VM::FLAG_BASIC_DEBUG)
        std::cerr << std::endl << "Calling order" << std::endl << "-------------" << std::endl;

    vm.exec(); vm.setMode(0);
    BENCHMARK_MRSTATS("", vm.exec(), 500, us)
    vm.saveBytecode("examples/bytecode/" + filename);

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

    // todo : do something intelligent with that shit
    passed_tests++;
}

void TEST(const std::string& name, kafe::bytecode_t bytecode)
{
    test_vm(name, "bytecode" + kafe::abc::str<int>(tests_count), bytecode);
}

void tests_report()
{
    std::cerr << "Report" << std::endl
              << "=================================" << std::endl
              << passed_tests << " test(s) passed out of " << tests_count << std::endl;
}

int start_tests(int mode)
{
    debug_mode = mode;

    std::cerr << "Useful pieces of information about Kafe" << std::endl;
    std::cerr << "\tSizeof(Kafe::Value)     = " << sizeof(kafe::Value) << "B" << std::endl;
    std::cerr << "\tSizeof(Kafe::VM)        = " << sizeof(kafe::VM) << "B" << std::endl;
    std::cerr << "\tSizeOf(Kafe::State)     = " << sizeof(kafe::State) << "B" << std::endl;
    std::cerr << "\tSizeof(Kafe::Function)  = " << sizeof(kafe::Function) << "B" << std::endl;
    std::cerr << "\tSizeof(Kafe::RefVar)    = " << sizeof(kafe::RefVar) << "B" << std::endl;
    std::cerr << "\tSizeof(Kafe::Call)      = " << sizeof(kafe::Call) << "B" << std::endl;
    std::cerr << "\tSizeof(Kafe::Structure) = " << sizeof(kafe::Structure) << "B" << std::endl;
    std::cerr << std::endl;

    TEST("int:18768, str:hello, bool:true", {
        kafe::INST_INT_2B, 0x49, 0x50,
        kafe::INST_STR, 'h', 'e', 'l', 'l', 'o', '\0',
        kafe::INST_BOOL, 'A',
        0x00
        });


    TEST("var = 1; push(var); push(9); add", {
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_STORE_DYN,
        kafe::INST_LOAD_VAR, 'v', 'a', 'r', '\0',
        kafe::INST_INT_2B, 0x00, 0x09,
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
        0x00
        });


    TEST("push true, jump if => 15, push false, jump => 7, jump if not, halt", {
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0f,
        kafe::INST_BOOL, 0x01,
        kafe::INST_JUMP_IF,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0f,
        kafe::INST_JUMP_IFN,
        kafe::INST_HALT,
        kafe::INST_BOOL, 0x00,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x08,
        kafe::INST_JUMP,
        0x00
        });


    /* equivalent :
    dyn a : bool = false
    fun var : bool
        ret true != a
    var()  # calling the function var
    */
    TEST("testing segments, jump and ret", {
        kafe::INST_BOOL, 0x00,
        kafe::INST_VAR, 'a', '\0',
        kafe::INST_STORE_DYN,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0d,
        kafe::INST_CALL,
        kafe::INST_HALT,
        kafe::INST_LOAD_VAR, 'a', '\0',
        kafe::INST_BOOL, 0x01,
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_NE),
        kafe::INST_RET,
        0x00
        });


    TEST("testing variable duplication and negatives numbers (-32767, 32767)", {
        kafe::INST_INT_2B, 0b10000000, 0b00000000,
        kafe::INST_VAR, 'h', '\0',
        kafe::INST_STORE_DYN,
        kafe::INST_LOAD_VAR, 'h', '\0',
        kafe::INST_DUP,
        kafe::INST_INT_2B, 0b01111111, 0b11111111,
        0x00
        });


    TEST("Fibonacci", {
        // (fibonacci 40)
        kafe::INST_INT_2B, 0x00, 0x28,
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0a,
        kafe::INST_CALL,

        kafe::INST_HALT,
        // func fibonacci : int -- n : int   -----> ADDR: 0x0a
        kafe::INST_VAR, 'n', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_INT_2B, 0x00, 0x00, // a = 0
        kafe::INST_VAR, 'a', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_INT_2B, 0x00, 0x01, // b = 1
        kafe::INST_VAR, 'b', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_INT_2B, 0x00, 0x00,  // i = 0
        kafe::INST_VAR, 'i', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_LOAD_VAR, 'a', '\0',  // c = a   <-------------- 0x23
        kafe::INST_VAR, 'c', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_LOAD_VAR, 'b', '\0',  // a = b
        kafe::INST_VAR, 'a', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_LOAD_VAR, 'b', '\0',  // b = b + c
        kafe::INST_LOAD_VAR, 'c', '\0',
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
        kafe::INST_VAR, 'b', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_LOAD_VAR, 'i', '\0',  // i = i + 1
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_ADD),
        kafe::INST_VAR, 'i', '\0',
        kafe::INST_STORE_DYN,

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
        });

    TEST("Fatorial", {
        kafe::INST_INT_2B, 0x00, 0x12,  // 18! = 6402373705728000
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0a,
        kafe::INST_CALL,
        kafe::INST_HALT,

        // start of the function
        kafe::INST_VAR, 'n', '\0',
        kafe::INST_STORE_DYN,

        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x21,  // addr = 33 --
        kafe::INST_LOAD_VAR, 'n', '\0',                     //  |
        kafe::INST_INT_2B, 0x00, 0x01,                      //  |
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_GR), // |
        kafe::INST_JUMP_IF,                                  // |
                                                             // |
        kafe::INST_INT_2B, 0x00, 0x01,                       // |
        kafe::INST_RET,                                      // |
                                                             // |
        kafe::INST_LOAD_VAR, 'n', '\0',    // <-----------------|
        kafe::INST_INT_2B, 0x00, 0x01,
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_SUB),
        kafe::INST_ADDR, 0x00, 0x00, 0x00, 0x0a,
        kafe::INST_CALL,
        kafe::INST_LOAD_VAR, 'n', '\0',
        kafe::INST_PROCEDURE, CALL_PROCEDURE(kafe::INST_MUL),
        kafe::INST_RET,

        0x00
        });

    
    tests_report();

    return (passed_tests == tests_count ? 0 : 1);
}
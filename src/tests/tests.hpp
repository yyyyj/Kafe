#ifndef kafe_tests
#define kafe_tests

#include "../kafe/kafe.hpp"

#include <string>

std::string replaceAll(std::string str, const std::string& from, const std::string& to);
std::string format(int number, std::size_t sz);
void test_vm(const std::string& test_name, kafe::bytecode_t bytecode);
void TEST(const std::string& name, kafe::bytecode_t bytecode);
void tests_report();
int start_tests(int mode);

#endif // kafe_tests

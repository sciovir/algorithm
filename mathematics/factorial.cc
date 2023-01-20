#include "utils/test.h"

namespace algorithm {
namespace mathematics {

int32_t Factorial(int32_t n) {
  if (n == 0) {
    return 1;
  }
  return n * Factorial(n - 1);
}

namespace test {

void Factorial_HandlesZeroInput() { EXPECT_EQ(Factorial(0), 1); }

void Factorial_HandlesPositiveInput() {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(6), 720);
  EXPECT_EQ(Factorial(8), 40320);
}

void RunTests() {
  TEST(Factorial_HandlesZeroInput);
  TEST(Factorial_HandlesPositiveInput);
}

}  // namespace test

}  // namespace mathematics
}  // namespace algorithm

int main() {
  std::cout << "-----Running factorial tests-----" << std::endl;
  algorithm::mathematics::test::RunTests();
  return 0;
}
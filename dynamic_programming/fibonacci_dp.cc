#include "utils/test.h"

namespace algorithm {
namespace dynamic_programming {

uint32_t FibonacciDP(const uint32_t n) {
  auto *fibonacci = new uint32_t[n + 1];
  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for (auto i = 2; i <= n; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }
  auto ret = fibonacci[n];
  delete[] fibonacci;
  return ret;
}

namespace test {

void FibonacciDP_HandlesZeroInput() { EXPECT_EQ(FibonacciDP(0), 0); }

void FibonacciDP_HandlesPositiveInput() {
  EXPECT_EQ(FibonacciDP(1), 1);
  EXPECT_EQ(FibonacciDP(2), 1);
  EXPECT_EQ(FibonacciDP(3), 2);
  EXPECT_EQ(FibonacciDP(6), 8);
}

void RunTests() {
  TEST(FibonacciDP_HandlesZeroInput);
  TEST(FibonacciDP_HandlesPositiveInput);
}

}  // namespace test

}  // namespace dynamic_programming
}  // namespace algorithm

int main() {
  std::cout << "-----Running fibonacci number DP tests-----" << std::endl;
  algorithm::dynamic_programming::test::RunTests();
  return 0;
}
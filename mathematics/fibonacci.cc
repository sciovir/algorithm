#include "utils/test.h"

namespace algorithm {
namespace mathematics {

uint32_t BinaryFibonacci(uint32_t n) {
  if (n <= 1) {
    return n;
  }
  return BinaryFibonacci(n - 1) + BinaryFibonacci(n - 2);
}

std::tuple<uint32_t, uint32_t> LinearFibonacci(uint32_t n) {
  if (n <= 1) {
    return std::make_tuple(n, 0);
  }
  std::tuple<uint32_t, uint32_t> ret = LinearFibonacci(n - 1);
  return std::make_tuple(std::get<0>(ret) + std::get<1>(ret), std::get<0>(ret));
}

namespace test {

void Fibonacci_HandlesZeroInput() {
  EXPECT_EQ(BinaryFibonacci(0), 0);
  EXPECT_EQ(std::get<0>(LinearFibonacci(0)), 0);
}

void Fibonacci_HandlesPositiveInput() {
  EXPECT_EQ(BinaryFibonacci(1), 1);
  EXPECT_EQ(BinaryFibonacci(2), 1);
  EXPECT_EQ(BinaryFibonacci(3), 2);
  EXPECT_EQ(BinaryFibonacci(6), 8);

  EXPECT_EQ(std::get<0>(LinearFibonacci(1)), 1);
  EXPECT_EQ(std::get<0>(LinearFibonacci(2)), 1);
  EXPECT_EQ(std::get<0>(LinearFibonacci(3)), 2);
  EXPECT_EQ(std::get<0>(LinearFibonacci(6)), 8);
}

void RunTests() {
  TEST(Fibonacci_HandlesZeroInput);
  TEST(Fibonacci_HandlesPositiveInput);
}

}  // namespace test

}  // namespace mathematics
}  // namespace algorithm

int main() {
  std::cout << "-----Running fibonacci tests-----" << std::endl;
  algorithm::mathematics::test::RunTests();
  return 0;
}
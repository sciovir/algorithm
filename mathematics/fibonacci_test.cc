#include "fibonacci.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(FibonacciTest, HandlesZeroInput) {
  EXPECT_EQ(mathematics::BinaryFibonacci(0), 0);
  EXPECT_EQ(std::get<0>(mathematics::LinearFibonacci(0)), 0);
}

TEST(FibonacciTest, HandlesPositiveInput) {
  EXPECT_EQ(mathematics::BinaryFibonacci(1), 1);
  EXPECT_EQ(mathematics::BinaryFibonacci(2), 1);
  EXPECT_EQ(mathematics::BinaryFibonacci(3), 2);
  EXPECT_EQ(mathematics::BinaryFibonacci(6), 8);

  EXPECT_EQ(std::get<0>(mathematics::LinearFibonacci(1)), 1);
  EXPECT_EQ(std::get<0>(mathematics::LinearFibonacci(2)), 1);
  EXPECT_EQ(std::get<0>(mathematics::LinearFibonacci(3)), 2);
  EXPECT_EQ(std::get<0>(mathematics::LinearFibonacci(6)), 8);
}

TEST(FibonacciTest, HandlesNegativeInput) {
  EXPECT_DEATH(mathematics::BinaryFibonacci(-1), "");
  EXPECT_DEATH(mathematics::BinaryFibonacci(-100), "");

  EXPECT_DEATH(mathematics::LinearFibonacci(-1), "");
  EXPECT_DEATH(mathematics::LinearFibonacci(-100), "");
}

}  // namespace
}  // namespace algorithm

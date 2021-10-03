#include "fibonacci.h"

#include <gtest/gtest.h>

TEST(FibonacciTest, HandlesZeroInput) {
  EXPECT_EQ(algorithm::mathematics::BinaryFibonacci(0), 0);
  EXPECT_EQ(std::get<0>(algorithm::mathematics::LinearFibonacci(0)), 0);
}

TEST(FibonacciTest, HandlesPositiveInput) {
  EXPECT_EQ(algorithm::mathematics::BinaryFibonacci(1), 1);
  EXPECT_EQ(algorithm::mathematics::BinaryFibonacci(2), 1);
  EXPECT_EQ(algorithm::mathematics::BinaryFibonacci(3), 2);
  EXPECT_EQ(algorithm::mathematics::BinaryFibonacci(6), 8);

  EXPECT_EQ(std::get<0>(algorithm::mathematics::LinearFibonacci(1)), 1);
  EXPECT_EQ(std::get<0>(algorithm::mathematics::LinearFibonacci(2)), 1);
  EXPECT_EQ(std::get<0>(algorithm::mathematics::LinearFibonacci(3)), 2);
  EXPECT_EQ(std::get<0>(algorithm::mathematics::LinearFibonacci(6)), 8);
}

TEST(FibonacciTest, HandlesNegativeInput) {
  EXPECT_DEATH(algorithm::mathematics::BinaryFibonacci(-1), "");
  EXPECT_DEATH(algorithm::mathematics::BinaryFibonacci(-100), "");

  EXPECT_DEATH(algorithm::mathematics::LinearFibonacci(-1), "");
  EXPECT_DEATH(algorithm::mathematics::LinearFibonacci(-100), "");
}

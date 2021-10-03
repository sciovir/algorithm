#include "factorial.h"

#include <gtest/gtest.h>

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(algorithm::mathematics::Factorial(0), 1);
}

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(algorithm::mathematics::Factorial(1), 1);
  EXPECT_EQ(algorithm::mathematics::Factorial(2), 2);
  EXPECT_EQ(algorithm::mathematics::Factorial(3), 6);
  EXPECT_EQ(algorithm::mathematics::Factorial(6), 720);
  EXPECT_EQ(algorithm::mathematics::Factorial(8), 40320);
}

TEST(FactorialTest, HandlesNegativeInput) {
  EXPECT_DEATH(algorithm::mathematics::Factorial(-1), "");
  EXPECT_DEATH(algorithm::mathematics::Factorial(-100), "");
  EXPECT_DEATH(algorithm::mathematics::Factorial(-10), "");
}

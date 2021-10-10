#include "factorial.h"

#include <gtest/gtest.h>

namespace algorithm {

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(mathematics::Factorial(0), 1);
}

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(mathematics::Factorial(1), 1);
  EXPECT_EQ(mathematics::Factorial(2), 2);
  EXPECT_EQ(mathematics::Factorial(3), 6);
  EXPECT_EQ(mathematics::Factorial(6), 720);
  EXPECT_EQ(mathematics::Factorial(8), 40320);
}

TEST(FactorialTest, HandlesNegativeInput) {
  EXPECT_DEATH(mathematics::Factorial(-1), "");
  EXPECT_DEATH(mathematics::Factorial(-100), "");
  EXPECT_DEATH(mathematics::Factorial(-10), "");
}

}  // namespace algorithm

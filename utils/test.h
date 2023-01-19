#pragma once

#include <iostream>

namespace algorithm {
namespace test {

#define TEST(function)                                                      \
  try {                                                                     \
    function();                                                             \
    std::cout << #function << ": PASSED" << std::endl;                      \
  } catch (const std::exception& e) {                                       \
    std::cout << #function << ": FAILED (" << e.what() << ")" << std::endl; \
  }

#define EXPECT_EQ(expected, actual)                             \
  if ((expected) != (actual)) {                                 \
    std::cerr << "Assertion failed, Expected: " << #expected    \
              << " == " << #actual << " ( Actual: " << expected \
              << " != " << actual << " )" << std::endl;         \
    exit(1);                                                    \
  }

#define EXPECT_ARR_EQ(expected, actual)                                     \
  {                                                                         \
    if ((std::size(expected)) != (std::size(actual))) {                     \
      std::cout << "Assertion failed: " << #expected << " == " << #actual   \
                << " ( arrays have different sizes )" << std::endl;         \
      exit(1);                                                              \
    }                                                                       \
    for (int i = 0; i < std::size(expected); ++i)                           \
      if (expected[i] != actual[i]) {                                       \
        std::cout << "Assertion failed: " << #expected << " == " << #actual \
                  << " ( " << expected[i] << " != " << actual[i] << " )"    \
                  << std::endl;                                             \
        exit(1);                                                            \
      }                                                                     \
  }

}  // namespace test
}  // namespace algorithm

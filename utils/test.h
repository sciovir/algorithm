#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>

namespace algorithm {
namespace test {

#define TEST(function)                                                      \
  try {                                                                     \
    function();                                                             \
    std::cout << #function << ": PASSED" << std::endl;                      \
  } catch (const std::exception& e) {                                       \
    std::cerr << #function << ": FAILED (" << e.what() << ")" << std::endl; \
  }

#define EXPECT_EQ(expected, actual)                             \
  if ((expected) != (actual)) {                                 \
    std::cerr << "Assertion failed, Expected: " << #expected    \
              << " == " << #actual << " ( Actual: " << expected \
              << " != " << actual << " )" << std::endl;         \
    exit(1);                                                    \
  }

#define EXPECT_ARR_EQ(expected, actual)                                 \
  if (!std::equal(std::begin(expected), std::end(expected),             \
                  std::begin(actual), std::end(actual)) ||              \
      std::distance(std::begin(expected), std::end(expected)) !=        \
          std::distance(std::begin(actual), std::end(actual))) {        \
    std::cerr << "Assertion failed: " << #expected << " != " << #actual \
              << " ( arrays are not equal )" << std::endl;              \
    exit(1);                                                            \
  }

}  // namespace test
}  // namespace algorithm

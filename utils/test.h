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

}  // namespace test
}  // namespace algorithm

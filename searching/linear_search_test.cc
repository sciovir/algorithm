#include "linear_search.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

int integers[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
std::string strings[7] = {"c", "cpp", "go", "java", "python", "sql", "swift"};
float floats[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

TEST(LinearSearchTest, HandlesMultipleTypesOfArrayInput) {
  EXPECT_EQ(searching::LinearSearch(integers, 8), 4);
  EXPECT_EQ(searching::LinearSearch(strings, (std::string) "cpp"), 1);
  EXPECT_EQ(searching::LinearSearch(floats, 9.5f), 7);
}

TEST(LinearSearchTest, HandlesNonExistElementInput) {
  EXPECT_EQ(searching::LinearSearch(integers, 1), -1);
  EXPECT_EQ(searching::LinearSearch(strings, (std::string) "rust"), -1);
  EXPECT_EQ(searching::LinearSearch(floats, 4.5f), -1);
}

}  // namespace
}  // namespace algorithm

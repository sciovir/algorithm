#include "binary_search.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

int integers[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
std::string strings[7] = {"c", "cpp", "go", "java", "python", "sql", "swift"};
float floats[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

TEST(BinarySearchTest, HandlesMultipleTypesOfArrayInput) {
  EXPECT_EQ(searching::BinarySearch(integers, 8, 0,
                                    sizeof(integers) / sizeof(*integers) - 1),
            4);
  EXPECT_EQ(searching::BinarySearch(strings, (std::string) "cpp", 0,
                                    sizeof(strings) / sizeof(*strings) - 1),
            1);
  EXPECT_EQ(searching::BinarySearch(floats, 9.5f, 0,
                                    sizeof(floats) / sizeof(*floats) - 1),
            7);
}

TEST(BinarySearchTest, HandlesNonExistElementInput) {
  EXPECT_EQ(searching::BinarySearch(integers, 1, 0,
                                    sizeof(integers) / sizeof(*integers) - 1),
            -1);
  EXPECT_EQ(searching::BinarySearch(strings, (std::string) "rust", 0,
                                    sizeof(strings) / sizeof(*strings) - 1),
            -1);
  EXPECT_EQ(searching::BinarySearch(floats, 4.5f, 0,
                                    sizeof(floats) / sizeof(*floats) - 1),
            -1);
}

}  // namespace
}  // namespace algorithm

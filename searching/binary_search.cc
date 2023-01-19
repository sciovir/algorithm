#include "utils/test.h"

namespace algorithm {
namespace searching {

template <class T, std::size_t N>
int32_t BinarySearch(T (&array)[N], T key, int32_t lo, int32_t hi) {
  if (lo > hi) {
    return -1;
  }

  int32_t mi = (lo + hi) / 2;
  if (array[mi] == key) {
    return mi;
  } else if (key < array[mi]) {
    return BinarySearch(array, key, lo, mi - 1);
  }
  return BinarySearch(array, key, mi + 1, hi);
}

namespace test {

int32_t ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
std::string strs[7] = {"c", "cpp", "go", "java", "python", "sql", "swift"};
float flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

void BinarySearch_TestHandlesMultipleTypesOfArrayInput() {
  EXPECT_EQ(BinarySearch(ints, 8, 0, std::size(ints) - 1), 4);
  EXPECT_EQ(BinarySearch(strs, (std::string) "cpp", 0, std::size(strs) - 1), 1);
  EXPECT_EQ(BinarySearch(flts, 9.5f, 0, std::size(flts) - 1), 7);
}

void BinarySearch_TestHandlesNonExistElementInput() {
  EXPECT_EQ(BinarySearch(ints, 1, 0, std::size(ints) - 1), -1);
  EXPECT_EQ(BinarySearch(strs, (std::string) "rust", 0, std::size(strs) - 1),
            -1);
  EXPECT_EQ(BinarySearch(flts, 4.5f, 0, std::size(flts) - 1), -1);
}

void RunTests() {
  TEST(BinarySearch_TestHandlesMultipleTypesOfArrayInput);
  TEST(BinarySearch_TestHandlesNonExistElementInput);
}

}  // namespace test

}  // namespace searching
}  // namespace algorithm

int main() {
  std::cout << "-----Running binary search tests-----" << std::endl;
  algorithm::searching::test::RunTests();
  return 0;
}
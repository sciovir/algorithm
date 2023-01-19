#include "utils/test.h"

namespace algorithm {
namespace searching {

template <class T, std::size_t N>
int32_t LinearSearch(T (&array)[N], T key) {
  for (auto i = 0; i < N; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}

namespace test {

int32_t ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
std::string strs[7] = {"c", "cpp", "go", "java", "python", "sql", "swift"};
float flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

void LinearSearch_TestHandlesMultipleTypesOfArrayInput() {
  EXPECT_EQ(LinearSearch(ints, 8), 4);
  EXPECT_EQ(LinearSearch(strs, (std::string) "cpp"), 1);
  EXPECT_EQ(LinearSearch(flts, 9.5f), 7);
}

void LinearSearch_TestHandlesNonExistElementInput() {
  EXPECT_EQ(LinearSearch(ints, 1), -1);
  EXPECT_EQ(LinearSearch(strs, (std::string) "rust"), -1);
  EXPECT_EQ(LinearSearch(flts, 4.5f), -1);
}

void RunTests() {
  TEST(LinearSearch_TestHandlesMultipleTypesOfArrayInput);
  TEST(LinearSearch_TestHandlesNonExistElementInput);
}

}  // namespace test

}  // namespace searching
}  // namespace algorithm

int main() {
  std::cout << "-----Running linear search tests-----" << std::endl;
  algorithm::searching::test::RunTests();
  return 0;
}
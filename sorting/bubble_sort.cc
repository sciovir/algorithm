#include "utils/test.h"

namespace algorithm {
namespace sorting {

/**
 * Bubble Sort works by repeatedly swapping the elements if they are in wrong
 * order.
 * @tparam T array's class
 * @tparam N size of array
 * @param array unsorted array
 *
 * Examples:
 *  - Giving an array [5, 2, 3, 1, 4], assuming that we sort the array by
 * ascending order.
 *  - Starting with the first index, we compare the element at current index
 * with the rest. At the end of first loop, we get the smallest element at
 * current index.
 *   0  1  2  3  4 -> array's indexes
 *  [5, 2, 3, 1, 4] we compare
 * the first 2 elements then swap 5 and 2 cause 5 > 2
 *   i     j
 *  [2, 5, 3, 1, 4]
 * since these elements are in order (2 < 3), we don't swap them
 *   i        j
 *  [2, 5, 3, 1, 4]
 * swap 2 and 1
 *   i           j
 *  [1, 5, 3, 2, 4] don't swap
 *  - Keep looping i to pre-last index and j from i + 1 to the last index.
 *  - After all the loops, array is now sorted.
 */
template <typename T, std::size_t N>
void BubbleSort(T (&array)[N]) {
  for (auto i = 0; i < N - 1; i++) {
    for (auto j = i + 1; j < N; j++) {
      if (array[i] > array[j]) {
        std::swap(array[i], array[j]);
      }
    }
  }
}

namespace test {

void BubbleSort_TestHandlesMultipleTypesOfArrayInput() {
  int ints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strs[7] = {"c", "java", "cpp", "python", "go", "sql", "swift"};
  float flts[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  int32_t sorted_ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string sorted_strs[7] = {"c",      "cpp", "go",   "java",
                                "python", "sql", "swift"};
  float sorted_flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  BubbleSort(ints);
  EXPECT_ARR_EQ(ints, sorted_ints);

  BubbleSort(strs);
  EXPECT_ARR_EQ(strs, sorted_strs);

  BubbleSort(flts);
  EXPECT_ARR_EQ(flts, sorted_flts);
}

void RunTests() { TEST(BubbleSort_TestHandlesMultipleTypesOfArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running bubble sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
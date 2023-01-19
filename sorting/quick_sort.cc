#include "utils/test.h"

namespace algorithm {
namespace sorting {

template <typename T, std::size_t N>
uint32_t Partition(T (&array)[N], int32_t lo, int32_t hi, bool hoare) {
  if (hoare) {
    auto pivot = array[lo];
    auto i = lo, j = hi;
    while (true) {
      while (array[i] < pivot) {
        i++;
      }
      while (array[j] > pivot) {
        j--;
      }
      if (i < j) {
        std::swap(array[i], array[j]);
      } else {
        return j;
      }
    }
  } else {
    auto pivot = array[hi];
    auto i = lo - 1;
    for (auto j = lo; j < hi; j++) {
      if (array[j] < pivot) {
        std::swap(array[++i], array[j]);
      }
    }
    std::swap(array[i + 1], array[hi]);
    return i + 1;
  }
}

template <typename T, std::size_t N>
void QuickSort(T (&array)[N], int32_t lo, int32_t hi) {
  if (lo < hi) {
    uint32_t separator = Partition(array, lo, hi, true);
    QuickSort(array, lo, separator - 1);
    QuickSort(array, separator + 1, hi);
  }
}

namespace test {

void QuickSort_TestHandlesMultipleTypesOfArrayInput() {
  int32_t ints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strs[7] = {"c", "java", "cpp", "python", "go", "sql", "swift"};
  float flts[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  int32_t sorted_ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string sorted_strs[7] = {"c",      "cpp", "go",   "java",
                                "python", "sql", "swift"};
  float sorted_flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  QuickSort(ints, 0, std::size(ints) - 1);
  EXPECT_ARR_EQ(ints, sorted_ints);

  QuickSort(strs, 0, std::size(strs) - 1);
  EXPECT_ARR_EQ(strs, sorted_strs);

  QuickSort(flts, 0, std::size(flts) - 1);
  EXPECT_ARR_EQ(flts, sorted_flts);
}

void RunTests() { TEST(QuickSort_TestHandlesMultipleTypesOfArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running quick sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
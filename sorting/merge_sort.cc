#include "utils/test.h"

namespace algorithm {
namespace sorting {

template <typename T, std::size_t N>
void Merge(T (&array)[N], int32_t lo, int32_t mi, int32_t hi) {
  auto l_len = mi - lo + 1, r_len = hi - mi;
  auto *l_arr = new T[l_len], *r_arr = new T[r_len];

  for (auto i = 0; i < l_len; i++) {
    l_arr[i] = array[lo + i];
  }
  for (auto i = 0; i < r_len; i++) {
    r_arr[i] = array[mi + 1 + i];
  }

  auto i = 0, j = 0, k = lo;
  while (i < l_len && j < r_len) {
    array[k++] = l_arr[i] <= r_arr[j] ? l_arr[i++] : r_arr[j++];
  }
  while (i < l_len) {
    array[k++] = l_arr[i++];
  }
  while (j < r_len) {
    array[k++] = r_arr[j++];
  }

  delete[] l_arr;
  delete[] r_arr;
}

template <typename T, std::size_t N>
void MergeSort(T (&array)[N], int32_t lo, int32_t hi) {
  if (lo < hi) {
    int32_t mi = (lo + hi) / 2;
    MergeSort(array, lo, mi);
    MergeSort(array, mi + 1, hi);
    Merge(array, lo, mi, hi);
  }
}

namespace test {

void MergeSort_TestHandlesMultipleTypesOfArrayInput() {
  int32_t ints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strs[7] = {"c", "java", "cpp", "python", "go", "sql", "swift"};
  float flts[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  int32_t sorted_ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string sorted_strs[7] = {"c",      "cpp", "go",   "java",
                                "python", "sql", "swift"};
  float sorted_flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  MergeSort(ints, 0, std::size(ints) - 1);
  EXPECT_ARR_EQ(ints, sorted_ints);

  MergeSort(strs, 0, std::size(strs) - 1);
  EXPECT_ARR_EQ(strs, sorted_strs);

  MergeSort(flts, 0, std::size(flts) - 1);
  EXPECT_ARR_EQ(flts, sorted_flts);
}

void RunTests() { TEST(MergeSort_TestHandlesMultipleTypesOfArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running merge sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
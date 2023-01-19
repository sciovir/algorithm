#include "data_structure/heap/max_heap.h"
#include "utils/test.h"

namespace algorithm {
namespace sorting {

template <typename T, std::size_t N>
void HeapSort(T (&array)[N]) {
  data_structure::heap::MaxHeap<T> max_heap(array);

  for (auto i = N - 1; i > 0; i--) {
    max_heap.Swap(0, i);
    max_heap.SetSize(max_heap.GetSize() - 1);
    max_heap.Heapify(0);
  }

  for (auto i = 0; i < N; i++) {
    array[i] = max_heap.GetData()[i];
  }
}

namespace test {

void HeapSort_TestHandlesMultipleTypesOfArrayInput() {
  int32_t ints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strs[7] = {"c", "java", "cpp", "python", "go", "sql", "swift"};
  float flts[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  int32_t sorted_ints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string sorted_strs[7] = {"c",      "cpp", "go",   "java",
                                "python", "sql", "swift"};
  float sorted_flts[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  HeapSort(ints);
  EXPECT_ARR_EQ(ints, sorted_ints);

  HeapSort(strs);
  EXPECT_ARR_EQ(strs, sorted_strs);

  HeapSort(flts);
  EXPECT_ARR_EQ(flts, sorted_flts);
}

void RunTests() { TEST(HeapSort_TestHandlesMultipleTypesOfArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running heap sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
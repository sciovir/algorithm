#include "data_structure/heap/max_heap.h"
#include "sorting_util.h"

namespace algorithm {
namespace sorting {

template <class T, size_t N>
void HeapSort(T (&array)[N]) {
  data_structure::heap::MaxHeap<T> max_heap(array);
  for (int i = N - 1; i > 0; i--) {
    max_heap.Swap(0, i);
    max_heap.SetSize(max_heap.GetSize() - 1);
    max_heap.Heapify(0);
  }
  for (unsigned int i = 0; i < N; i++) array[i] = max_heap.GetData()[i];
}

}  // namespace sorting
}  // namespace algorithm

int main() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[7] = {"c",  "java",  "cpp",        "python",
                            "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithm::sorting::HeapSort(integers);
  std::cout << "Sorted integer array: ";
  algorithm::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithm::sorting::HeapSort(strings);
  std::cout << "Sorted string array: ";
  algorithm::sorting::PrintArray(
      strings);  // c cpp go java objective-c python swift

  algorithm::sorting::HeapSort(floats);
  std::cout << "Sorted float array: ";
  algorithm::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}

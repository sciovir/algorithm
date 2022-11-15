#include <algorithm>

#include "sorting_util.h"

namespace algorithm {
namespace sorting {

template <class T, size_t N>
void CountingSort(T (&array)[N], T key) {
  if (!std::is_same<T, unsigned>::value &&
      !std::is_same<T, unsigned char>::value) {
    throw std::runtime_error(
        "Only accept non-negative integer or character array.");
  }

  auto *output = new T[N];
  auto *auxiliary = new T[key + 1];

  for (auto i = 0; i < (unsigned)(key + 1); i++) {
    auxiliary[i] = 0;
  }

  for (auto element : array) {
    auxiliary[element]++;
  }

  for (auto i = 1; i < (unsigned)(key + 1); i++) {
    auxiliary[i] += auxiliary[i - 1];
  }

  for (int i = N - 1; i >= 0; i--) {
    output[auxiliary[array[i]] - 1] = array[i];
    auxiliary[array[i]]--;
  }

  for (unsigned i = 0; i < N; i++) {
    array[i] = output[i];
  }

  delete[] auxiliary;
  delete[] output;
}

}  // namespace sorting
}  // namespace algorithm

int main() {
  unsigned int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  unsigned char chars[8] = {'d', 'g', 'a', 'b', 'j', 'y', 'h', 'k'};

  algorithm::sorting::CountingSort(
      integers, *(std::max_element(integers, integers + 11)));
  std::cout << "Sorted integer array: ";
  algorithm::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithm::sorting::CountingSort(chars,
                                   *(std::max_element(chars, chars + 8)));
  std::cout << "Sorted character array: ";
  algorithm::sorting::PrintArray(chars);  // a b d g h j k y

  return 0;
}

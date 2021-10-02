#ifndef ALGORITHM_SORTING_SORTING_UTIL_H_
#define ALGORITHM_SORTING_SORTING_UTIL_H_

#include <iostream>

namespace algorithm {
namespace sorting {

template <class T, size_t N>
void PrintArray(const T (&array)[N]) {
  for (T item : array) std::cout << item << " ";
  std::cout << std::endl;
}

}  // namespace sorting
}  // namespace algorithm

#endif  // ALGORITHM_SORTING_SORTING_UTIL_H_

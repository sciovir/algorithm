#pragma once

#include <iostream>

namespace algorithm {
namespace sorting {

template <class T, size_t N>
inline void PrintArray(const T (&array)[N]) {
  for (auto item : array) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

}  // namespace sorting
}  // namespace algorithm

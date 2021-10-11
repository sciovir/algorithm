#ifndef ALGORITHM_SEARCHING_BINARY_SEARCH_H_
#define ALGORITHM_SEARCHING_BINARY_SEARCH_H_

namespace algorithm {
namespace searching {

template <class T, size_t N>
int BinarySearch(T (&array)[N], T key, int low, int high);

}  // namespace searching
}  // namespace algorithm

#include "binary_search.cc"

#endif  // ALGORITHM_SEARCHING_BINARY_SEARCH_H_
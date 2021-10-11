#ifndef ALGORITHM_SEARCHING_LINEAR_SEARCH_H_
#define ALGORITHM_SEARCHING_LINEAR_SEARCH_H_

#include <iostream>

namespace algorithm {
namespace searching {

template <class T, size_t N>
int LinearSearch(T (&array)[N], T key);

}  // namespace searching
}  // namespace algorithm

#include "linear_search.cc"

#endif  // ALGORITHM_SEARCHING_LINEAR_SEARCH_H_
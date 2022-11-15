#pragma once

namespace algorithm {
namespace searching {

template <class T, size_t N>
int LinearSearch(T (&array)[N], T key);

}  // namespace searching
}  // namespace algorithm

#include "linear_search.cc"
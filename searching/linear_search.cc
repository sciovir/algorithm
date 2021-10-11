#include "linear_search.h"

namespace algorithm {
namespace searching {

template <class T, size_t N>
int LinearSearch(T (&array)[N], T key) {
  for (unsigned int i = 0; i < N; i++)
    if (array[i] == key) return i;
  return -1;
}

}  // namespace searching
}  // namespace algorithm
#include "binary_search.h"

namespace algorithm {
namespace searching {

template <class T, size_t N>
int BinarySearch(T (&array)[N], T key, int lo, int hi) {
  if (lo > hi) return -1;
  int mi = (lo + hi) / 2;
  if (array[mi] == key)
    return mi;
  else if (key < array[mi])
    return BinarySearch(array, key, lo, mi - 1);
  else
    return BinarySearch(array, key, mi + 1, hi);
}

}  // namespace searching
}  // namespace algorithm
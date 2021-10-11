#include "naive_pattern_searching.h"

namespace algorithm {
namespace pattern_searching {

template <size_t N, size_t M>
std::vector<int> NaivePatternSearching(const char (&text)[N],
                                       const char (&pattern)[M]) {
  if (N < 2 || M < 2 || N < M) {
    return std::vector<int>();
  }

  std::vector<int> ret;

  for (unsigned int i = 0; i < N - M; i++) {
    bool matched = true;
    for (unsigned int j = 0; j < M - 1; j++) {
      if (text[i + j] != pattern[j]) {
        matched = false;
        break;
      }
    }
    if (matched) {
      ret.push_back(i);
    }
  }

  return ret;
}

}  // namespace pattern_searching
}  // namespace algorithm
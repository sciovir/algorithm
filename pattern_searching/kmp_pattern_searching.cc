#include "kmp_pattern_searching.h"

namespace algorithm {
namespace pattern_searching {

template <size_t N, size_t M>
std::vector<int> KMPPatternSearching(const char (&text)[N],
                                     const char (&pattern)[M]) {
  unsigned int lps[M];
  unsigned int i = 1, j = 0;
  std::vector<int> ret;

  lps[0] = 0;
  while (i < M) {
    if (pattern[i] == pattern[j])
      lps[i++] = ++j;
    else if (j > 0)
      j = lps[j - 1];
    else
      lps[i++] = 0;
  }

  i = 0, j = 0;
  while (i < N) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    }
    if (j == M - 1) {
      ret.push_back(i - j);
      j = lps[j - 1];
    } else if (i < N && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  return ret;
}

}  // namespace pattern_searching
}  // namespace algorithm
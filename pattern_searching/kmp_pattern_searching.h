#ifndef ALGORITHM_PATTERN_SEARCHING_KMP_H_
#define ALGORITHM_PATTERN_SEARCHING_KMP_H_

#include <vector>

namespace algorithm {
namespace pattern_searching {

template <size_t N, size_t M>
std::vector<int> KMPPatternSearching(const char (&text)[N],
                                     const char (&pattern)[M]);

}  // namespace pattern_searching
}  // namespace algorithm

#include "kmp_pattern_searching.cc"

#endif  // ALGORITHM_PATTERN_SEARCHING_KMP_H_

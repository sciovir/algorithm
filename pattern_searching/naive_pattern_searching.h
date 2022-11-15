#pragma once
#include <vector>

namespace algorithm {
namespace pattern_searching {

template <size_t N, size_t M>
std::vector<int> NaivePatternSearching(const char (&text)[N],
                                       const char (&pattern)[M]);

}  // namespace pattern_searching
}  // namespace algorithm

#include "naive_pattern_searching.cc"
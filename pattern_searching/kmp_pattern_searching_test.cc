#include "kmp_pattern_searching.h"

#include <gtest/gtest.h>

namespace algorithm {

TEST(KMPPatternSearchingTest, HandlesMultipleTextAndPatternInput) {
  std::vector<int> ret =
      pattern_searching::KMPPatternSearching("AABAACAADAABAAABAA", "AABA");
  std::vector<int> result{0, 9, 13};
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }
}

}  // namespace algorithm
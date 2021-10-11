#include "kmp_pattern_searching.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(KMPPatternSearchingTest, HandlesMultiplePatternInput) {
  std::vector<int> ret =
      pattern_searching::KMPPatternSearching("AABAACAADAABAAABAA", "AABA");
  std::vector<int> result{0, 9, 13};
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = pattern_searching::KMPPatternSearching("AAABSSSAAAOSI", "FHJK");
  result.clear();
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = pattern_searching::KMPPatternSearching("AAACAAIOAAADAAIS", "AAACA");
  result = {0};
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }
}

TEST(KMPPatternSearchingTest, HandlesInvalidInput) {
  EXPECT_EQ(pattern_searching::KMPPatternSearching("", "").size(), 0);
  EXPECT_EQ(pattern_searching::KMPPatternSearching("ABC", "").size(), 0);
  EXPECT_EQ(pattern_searching::KMPPatternSearching("", "DEF").size(), 0);
  EXPECT_EQ(pattern_searching::KMPPatternSearching("AA", "DEF").size(), 0);
}

}  // namespace
}  // namespace algorithm
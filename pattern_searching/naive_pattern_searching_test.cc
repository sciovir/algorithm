#include "naive_pattern_searching.h"

#include <gtest/gtest.h>

namespace algorithm {

TEST(NaivePatternSearchingTest, HandlesMultiplePatternInput) {
  std::vector<int> ret =
      pattern_searching::NaivePatternSearching("AABAACAADAABAAABAA", "AABA");
  std::vector<int> result{0, 9, 13};
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = pattern_searching::NaivePatternSearching("AAABSSSAAAOSI", "FHJK");
  result.clear();
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = pattern_searching::NaivePatternSearching("AAACAAIOAAADAAIS", "AAACA");
  result = {0};
  EXPECT_EQ(ret.size(), result.size());
  for (unsigned int i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }
}

TEST(NaivePatternSearchingTest, HandlesInvalidInput) {
  EXPECT_EQ(pattern_searching::NaivePatternSearching("", "").size(), 0);
  EXPECT_EQ(pattern_searching::NaivePatternSearching("ABC", "").size(), 0);
  EXPECT_EQ(pattern_searching::NaivePatternSearching("", "DEF").size(), 0);
  EXPECT_EQ(pattern_searching::NaivePatternSearching("AA", "DEF").size(), 0);
}

}  // namespace algorithm
#include <vector>

#include "utils/test.h"

namespace algorithm {
namespace pattern_searching {

template <std::size_t N, std::size_t M>
std::vector<int32_t> NaivePatternSearching(const char (&text)[N],
                                           const char (&pattern)[M]) {
  if (N < 2 || M < 2 || N < M) {
    return std::vector<int32_t>();
  }

  std::vector<int32_t> ret;

  for (auto i = 0; i < N - M; i++) {
    bool matched = true;
    for (auto j = 0; j < M - 1; j++) {
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

namespace test {

void NaivePatternSearching_HandlesMultiplePatternInput() {
  auto ret = NaivePatternSearching("AABAACAADAABAAABAA", "AABA");
  std::vector<int32_t> result{0, 9, 13};
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = NaivePatternSearching("AAABSSSAAAOSI", "FHJK");
  result.clear();
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = NaivePatternSearching("AAACAAIOAAADAAIS", "AAACA");
  result = {0};
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }
}

void NaivePatternSearching_HandlesInvalidInput() {
  EXPECT_EQ(NaivePatternSearching("", "").size(), 0);
  EXPECT_EQ(NaivePatternSearching("ABC", "").size(), 0);
  EXPECT_EQ(NaivePatternSearching("", "DEF").size(), 0);
  EXPECT_EQ(NaivePatternSearching("AA", "DEF").size(), 0);
}

void RunTests() {
  TEST(NaivePatternSearching_HandlesMultiplePatternInput);
  TEST(NaivePatternSearching_HandlesInvalidInput);
}

}  // namespace test

}  // namespace pattern_searching
}  // namespace algorithm

int main() {
  std::cout << "-----Running Naive pattern searching tests-----" << std::endl;
  algorithm::pattern_searching::test::RunTests();
  return 0;
}
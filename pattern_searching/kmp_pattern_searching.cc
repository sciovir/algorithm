#include <vector>

#include "utils/test.h"

namespace algorithm {
namespace pattern_searching {

template <std::size_t N, std::size_t M>
std::vector<int32_t> KMPPatternSearching(const char (&text)[N],
                                         const char (&pattern)[M]) {
  if (N < 2 || M < 2 || N < M) {
    return std::vector<int32_t>();
  }

  uint32_t lps[M];
  uint32_t i = 1, j = 0;
  std::vector<int32_t> ret;

  lps[0] = 0;
  while (i < M - 1) {
    if (pattern[i] == pattern[j]) {
      lps[i++] = ++j;
    } else if (j > 0) {
      j = lps[j - 1];
    } else {
      lps[i++] = 0;
    }
  }

  i = 0, j = 0;
  while (i < N - 1) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    }
    if (j == M - 1) {
      ret.push_back(i - j);
      j = lps[j - 1];
    } else if (i < N - 1 && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  return ret;
}

namespace test {

void KMPPatternSearching_HandlesMultiplePatternInput() {
  auto ret = KMPPatternSearching("AABAACAADAABAAABAA", "AABA");
  std::vector<int32_t> result{0, 9, 13};
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = KMPPatternSearching("AAABSSSAAAOSI", "FHJK");
  result.clear();
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }

  ret = KMPPatternSearching("AAACAAIOAAADAAIS", "AAACA");
  result = {0};
  EXPECT_EQ(ret.size(), result.size());
  for (auto i = 0; i < ret.size(); i++) {
    EXPECT_EQ(ret[i], result[i]);
  }
}

void KMPPatternSearching_HandlesInvalidInput() {
  EXPECT_EQ(KMPPatternSearching("", "").size(), 0);
  EXPECT_EQ(KMPPatternSearching("ABC", "").size(), 0);
  EXPECT_EQ(KMPPatternSearching("", "DEF").size(), 0);
  EXPECT_EQ(KMPPatternSearching("AA", "DEF").size(), 0);
}

void RunTests() {
  TEST(KMPPatternSearching_HandlesMultiplePatternInput);
  TEST(KMPPatternSearching_HandlesInvalidInput);
}

}  // namespace test

}  // namespace pattern_searching
}  // namespace algorithm

int main() {
  std::cout << "-----Running KMP pattern searching tests-----" << std::endl;
  algorithm::pattern_searching::test::RunTests();
  return 0;
}
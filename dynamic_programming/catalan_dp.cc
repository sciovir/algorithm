#include "utils/test.h"

namespace algorithm {
namespace dynamic_programming {

uint32_t CatalanDP(const uint32_t n) {
  auto *catalan = new uint32_t[n + 1];
  catalan[0] = catalan[1] = 1;
  for (auto i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (auto j = 0; j < i; j++) {
      catalan[i] += catalan[j] * catalan[i - j - 1];
    }
  }
  auto ret = catalan[n];
  delete[] catalan;
  return ret;
}

namespace test {

void CatalanDP_HandlesZeroInput() { EXPECT_EQ(CatalanDP(0), 1); }

void CatalanDP_HandlesPositiveInput() {
  EXPECT_EQ(CatalanDP(1), 1);
  EXPECT_EQ(CatalanDP(2), 2);
  EXPECT_EQ(CatalanDP(3), 5);
  EXPECT_EQ(CatalanDP(4), 14);
  EXPECT_EQ(CatalanDP(5), 42);
  EXPECT_EQ(CatalanDP(9), 4862);
}

void RunTests() {
  TEST(CatalanDP_HandlesZeroInput);
  TEST(CatalanDP_HandlesPositiveInput);
}

}  // namespace test

}  // namespace dynamic_programming
}  // namespace algorithm

int main() {
  std::cout << "-----Running catalan number DP tests-----" << std::endl;
  algorithm::dynamic_programming::test::RunTests();
  return 0;
}
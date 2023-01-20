#include "utils/test.h"

namespace algorithm {
namespace mathematics {

uint32_t Catalan(uint32_t n) {
  if (n <= 1) {
    return 1;
  }

  uint32_t ret = 0;
  for (auto i = 0; i < n; i++) {
    ret += Catalan(i) * Catalan(n - i - 1);
  }
  return ret;
}

namespace test {

void Catalan_HandlesZeroInput() { EXPECT_EQ(Catalan(0), 1); }

void Catalan_HandlesPositiveInput() {
  EXPECT_EQ(Catalan(1), 1);
  EXPECT_EQ(Catalan(2), 2);
  EXPECT_EQ(Catalan(3), 5);
  EXPECT_EQ(Catalan(4), 14);
  EXPECT_EQ(Catalan(5), 42);
  EXPECT_EQ(Catalan(9), 4862);
}

void RunTests() {
  TEST(Catalan_HandlesZeroInput);
  TEST(Catalan_HandlesPositiveInput);
}

}  // namespace test

}  // namespace mathematics
}  // namespace algorithm

int main() {
  std::cout << "-----Running catalan number tests-----" << std::endl;
  algorithm::mathematics::test::RunTests();
  return 0;
}
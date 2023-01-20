#include "utils/test.h"

namespace algorithm {
namespace dynamic_programming {

uint32_t UglyNumber(uint32_t n) {
  auto *ugly_numbers = new uint32_t[n];
  uint32_t i2 = 0, i3 = 0, i5 = 0;
  uint32_t multiplication_2 = 2;
  uint32_t multiplication_3 = 3;
  uint32_t multiplication_5 = 5;
  uint32_t next_ugly_number = 1;
  ugly_numbers[0] = next_ugly_number;

  for (auto i = 1; i < n; i++) {
    next_ugly_number = std::min(multiplication_2,
                                std::min(multiplication_3, multiplication_5));
    ugly_numbers[i] = next_ugly_number;
    if (multiplication_2 == next_ugly_number) {
      multiplication_2 = ugly_numbers[++i2] * 2;
    }
    if (multiplication_3 == next_ugly_number) {
      multiplication_3 = ugly_numbers[++i3] * 3;
    }
    if (multiplication_5 == next_ugly_number) {
      multiplication_5 = ugly_numbers[++i5] * 5;
    }
  }

  delete[] ugly_numbers;
  return next_ugly_number;
}

namespace test {

void UglyNumber_HandlesMultipleInput() {
  EXPECT_EQ(UglyNumber(0), 1);
  EXPECT_EQ(UglyNumber(1), 1);
  EXPECT_EQ(UglyNumber(2), 2);
  EXPECT_EQ(UglyNumber(3), 3);
  EXPECT_EQ(UglyNumber(190), 13122);
}

void RunTests() { TEST(UglyNumber_HandlesMultipleInput); }

}  // namespace test

}  // namespace dynamic_programming
}  // namespace algorithm

int main() {
  std::cout << "-----Running ugly number tests-----" << std::endl;
  algorithm::dynamic_programming::test::RunTests();
  return 0;
}
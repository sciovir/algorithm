#include "utils/test.h"

namespace algorithm {
namespace sorting {

template <size_t N>
void DigitCountingSort(uint32_t (&array)[N], uint32_t position) {
  auto *output = new uint32_t[N];
  auto *auxiliary = new uint32_t[10];

  for (auto i = 0; i < 10 + 1; i++) {
    auxiliary[i] = 0;
  }
  for (auto element : array) {
    auxiliary[(element / position) % 10]++;
  }

  for (auto i = 1; i < 10 + 1; i++) {
    auxiliary[i] += auxiliary[i - 1];
  }
  for (int32_t i = N - 1; i >= 0; i--) {
    output[auxiliary[(array[i] / position) % 10] - 1] = array[i];
    auxiliary[(array[i] / position) % 10]--;
  }

  for (auto i = 0; i < N; i++) {
    array[i] = output[i];
  }

  delete[] auxiliary;
  delete[] output;
}

template <std::size_t N>
void RadixSort(uint32_t (&array)[N]) {
  auto max_element = *(std::max_element(array, array + N));
  for (auto pos = 1; max_element / pos > 0; pos *= 10) {
    DigitCountingSort(array, pos);
  }
}

namespace test {

void RadixSort_TestHandlesUnsignedIntegralArrayInput() {
  uint32_t uints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  uint32_t sorted_uints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};

  RadixSort(uints);
  EXPECT_ARR_EQ(uints, sorted_uints);
}

void RunTests() { TEST(RadixSort_TestHandlesUnsignedIntegralArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running radix sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
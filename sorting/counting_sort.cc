#include <algorithm>

#include "utils/test.h"

namespace algorithm {
namespace sorting {

template <typename T>
concept unsigned_integral = std::is_unsigned_v<T> && std::is_integral_v<T>;

template <unsigned_integral T, std::size_t N>
void CountingSort(T (&array)[N], T key) {
  auto *output = new T[N];
  auto *auxiliary = new T[key + 1];

  for (auto i = 0; i < key + 1; i++) {
    auxiliary[i] = 0;
  }
  for (auto element : array) {
    auxiliary[element]++;
  }

  for (auto i = 1; i < key + 1; i++) {
    auxiliary[i] += auxiliary[i - 1];
  }
  for (int32_t i = N - 1; i >= 0; i--) {
    output[auxiliary[array[i]] - 1] = array[i];
    auxiliary[array[i]]--;
  }

  for (auto i = 0; i < N; i++) {
    array[i] = output[i];
  }
  delete[] auxiliary;
  delete[] output;
}

namespace test {

void CountingSort_TestHandlesUnsignedIntegralArrayInput() {
  uint32_t uints[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  char8_t chrs[8] = {'d', 'g', 'a', 'b', 'j', 'y', 'h', 'k'};

  uint32_t sorted_uints[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  char8_t sorted_chrs[8] = {'a', 'b', 'd', 'g', 'h', 'j', 'k', 'y'};

  CountingSort(uints, *(std::max_element(uints, uints + std::size(uints))));
  EXPECT_ARR_EQ(uints, sorted_uints);

  CountingSort(chrs, *(std::max_element(chrs, chrs + std::size(chrs))));
  EXPECT_ARR_EQ(chrs, sorted_chrs);
}

void RunTests() { TEST(CountingSort_TestHandlesUnsignedIntegralArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running counting sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
#include <tuple>

#include "utils/test.h"

namespace algorithm {
namespace divide_conquer {

std::tuple<int32_t, int32_t, int32_t> MaxCrossingSubarray(const int32_t *array,
                                                          int32_t lo,
                                                          int32_t mi,
                                                          int32_t hi) {
  auto l_sum = INT_MIN, r_sum = INT_MIN;
  auto sum = 0, l_max = mi, r_max = mi + 1;

  for (auto i = mi; i >= lo; i--) {
    sum += array[i];
    if (sum > l_sum) {
      l_sum = sum;
      l_max = i;
    }
  }

  sum = 0;
  for (auto i = mi + 1; i <= hi; i++) {
    sum += array[i];
    if (sum > r_sum) {
      r_sum = sum;
      r_max = i;
    }
  }

  sum = l_sum + r_sum;
  if (l_sum > r_sum && l_sum > sum) {
    return std::make_tuple(l_max, mi, l_sum);
  } else if (r_sum > l_sum && r_sum > sum) {
    return std::make_tuple(mi + 1, r_max, r_sum);
  } else {
    return std::make_tuple(l_max, r_max, sum);
  }
}

std::tuple<int32_t, int32_t, int32_t> MaximumSubarray(const int32_t *array,
                                                      int32_t lo, int32_t hi) {
  if (lo == hi) {
    return std::make_tuple(lo, hi, array[lo]);
  }

  auto mi = (lo + hi) / 2;
  auto l_tuple = MaximumSubarray(array, lo, mi);
  auto r_tuple = MaximumSubarray(array, mi + 1, hi);
  auto c_tuple = MaxCrossingSubarray(array, lo, mi, hi);

  if (std::get<2>(l_tuple) > std::get<2>(r_tuple) &&
      std::get<2>(l_tuple) > std::get<2>(c_tuple)) {
    return l_tuple;
  }
  if (std::get<2>(r_tuple) > std::get<2>(l_tuple) &&
      std::get<2>(r_tuple) > std::get<2>(c_tuple)) {
    return r_tuple;
  }
  return c_tuple;
}

namespace test {

void MaximumSubarray_TestHandlesIntegerArrayInput() {
  int32_t arr[16] = {12, -2, -23, 18, -1,  -14, -21, 16,
                     19, -5, 10,  -3, -20, 13,  -4,  -7};
  auto ret = MaximumSubarray(arr, 0, std::size(arr) - 1);

  EXPECT_EQ(std::get<0>(ret), 7);
  EXPECT_EQ(std::get<1>(ret), 10);
  EXPECT_EQ(std::get<2>(ret), 40);
}

void RunTests() { TEST(MaximumSubarray_TestHandlesIntegerArrayInput); }

}  // namespace test

}  // namespace divide_conquer
}  // namespace algorithm

int main() {
  std::cout << "-----Running maximum subarray tests-----" << std::endl;
  algorithm::divide_conquer::test::RunTests();
  return 0;
}
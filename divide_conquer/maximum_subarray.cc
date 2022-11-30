#include <climits>
#include <cstdint>
#include <iostream>
#include <tuple>

namespace algorithm {
namespace divide_conquer {

std::tuple<int32_t, int32_t, int32_t>
MaxCrossingSubarray(const int32_t *array, int32_t lo, int32_t mi, int32_t hi) {
  int32_t l_sum = INT_MIN, r_sum = INT_MIN;
  int32_t sum = 0, l_max = mi, r_max = mi + 1;

  for (int32_t i = mi; i >= lo; i--) {
    sum += array[i];
    if (sum > l_sum) {
      l_sum = sum;
      l_max = i;
    }
  }

  sum = 0;
  for (int32_t i = mi + 1; i <= hi; i++) {
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
  }
  return std::make_tuple(l_max, r_max, sum);
}

std::tuple<int32_t, int32_t, int32_t> MaximumSubarray(const int32_t *array,
                                                      int32_t lo, int32_t hi) {
  if (lo == hi) {
    return std::make_tuple(lo, hi, array[lo]);
  }

  int mi = (lo + hi) / 2;
  std::tuple<int32_t, int32_t, int32_t> l_tuple =
      MaximumSubarray(array, lo, mi);
  std::tuple<int32_t, int32_t, int32_t> r_tuple =
      MaximumSubarray(array, mi + 1, hi);
  std::tuple<int32_t, int32_t, int32_t> c_tuple =
      MaxCrossingSubarray(array, lo, mi, hi);

  if (std::get<2>(l_tuple) > std::get<2>(r_tuple) &&
      std::get<2>(l_tuple) > std::get<2>(c_tuple))
    return l_tuple;
  if (std::get<2>(r_tuple) > std::get<2>(l_tuple) &&
      std::get<2>(r_tuple) > std::get<2>(c_tuple))
    return r_tuple;
  return c_tuple;
}

} // namespace divide_conquer
} // namespace algorithm

int main() {
  int32_t arr[16] = {12, -2, -23, 18, -1,  -14, -21, 16,
                     19, -5, 10,  -3, -20, 13,  -4,  -7};
  std::tuple<int32_t, int32_t, int32_t> ret =
      algorithm::divide_conquer::MaximumSubarray(
          arr, 0, sizeof(arr) / sizeof(*arr) - 1);

  std::cout << "Start: " << std::get<0>(ret) << std::endl; // 7
  std::cout << "End: " << std::get<1>(ret) << std::endl;   // 10
  std::cout << "Sum: " << std::get<2>(ret) << std::endl;   // 40

  return 0;
}

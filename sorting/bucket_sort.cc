#include <algorithm>
#include <cassert>
#include <vector>

#include "utils/test.h"

namespace algorithm {
namespace sorting {

/**
 * Bubble Sort is mainly useful when sorting a large set of floating point
 * numbers which are in range [0, 1). It works by distributing elements to
 * buckets, then sorts each bucket and finally concatenates all sorted buckets.
 * @tparam T T array's class
 * @tparam N size of array
 * @param array unsorted array (non-negative floating point number array in
 * range [0, 1))
 *
 * Examples:
 *  - Giving an array [0.52, 0.12, 0.86, 0.29, 0.46, 0.4, 0.18, 0.6], 10 buckets
 * and assuming that we sort the array by ascending order.
 *  - Distributing all the elements to corresponding buckets by multiplying the
 * element and buckets' slots. Each bucket is a linked list. [0.52, 0.12, 0.86,
 * 0.29, 0.46, 0.4, 0.18, 0.6] -> array
 *    [[], [], [], [], [], [], [], [], [], []] -> buckets
 *    [0 []
 *     1 [] -> [0.12] -> [0.18]   0.12 * 10 = 1.2, 0.18 * 10 = 1.8
 *     2 [] -> [0.29]   0.29 * 10 = 2.9
 *     3 []
 *     4 [] -> [0.46] -> [0.4]   0.46 * 10 = 4.6, 0.4 * 10 = 4.0
 *     5 [] -> [0.52]   0.52 * 10 = 5.2
 *     6 [] -> [0.6]
 *     7 []
 *     8 [] -> [0.86]   0.86 * 10 = 8.6
 *     9 []
 *     ]
 *  - We sort each bucket using insertion sort.
 *    [[], [0.12, 0.18], [0.29], [], [0.4, 0.46], [0.52], [0.6], [], [0.86], []]
 *  - Concatenating all non-empty buckets, array is now sorted.
 */
template <typename T>
concept floating_point = std::is_same_v<T, float> || std::is_same_v<T, double>;

template <floating_point T, std::size_t N>
void BucketSort(T (&array)[N]) {
  bool in_range =
      std::all_of(array, array + N, [](auto x) { return (0 <= x) && (x < 1); });
  if (!in_range) {
    throw std::out_of_range(
        "Only accept non-negative floating point array in range [0, 1).");
  }

  constexpr uint32_t slots = 10;
  std::vector<T> buckets[slots];
  for (auto i = 0; i < N; i++) {
    uint32_t bucket_index = slots * array[i];
    buckets[bucket_index].push_back(array[i]);
  }

  uint32_t index = 0;
  for (auto i = 0; i < slots; i++) {
    sort(buckets[i].begin(), buckets[i].end());
    for (auto j = 0; j < buckets[i].size(); j++) {
      array[index++] = buckets[i][j];
    }
  }
}

namespace test {

void BucketSort_TestHandlesFloatingPointArrayInput() {
  float flts[8] = {0.52f, 0.44f, 0.68f, 0.95f, 0.1f, 0.12f, 0.32f, 0.59f};
  double dbls[8] = {0.52, 0.44, 0.68, 0.95, 0.1, 0.12, 0.32, 0.59};

  float sorted_flts[8] = {0.1f,  0.12f, 0.32f, 0.44f,
                          0.52f, 0.59f, 0.68f, 0.95f};
  double sorted_dbls[8] = {0.1, 0.12, 0.32, 0.44, 0.52, 0.59, 0.68, 0.95};

  BucketSort(flts);
  EXPECT_ARR_EQ(flts, sorted_flts);

  BucketSort(dbls);
  EXPECT_ARR_EQ(dbls, sorted_dbls);
}

void RunTests() { TEST(BucketSort_TestHandlesFloatingPointArrayInput); }

}  // namespace test

}  // namespace sorting
}  // namespace algorithm

int main() {
  std::cout << "-----Running bucket sort tests-----" << std::endl;
  algorithm::sorting::test::RunTests();
  return 0;
}
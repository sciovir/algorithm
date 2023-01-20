#include <tuple>

#include "utils/test.h"

namespace algorithm {
namespace dynamic_programming {

bool ZeroOneKnapsackItemComparator(const std::tuple<uint32_t, uint32_t> a,
                                   const std::tuple<uint32_t, uint32_t> b) {
  return std::get<0>(a) < std::get<0>(b);
}

template <std::size_t N>
uint32_t ZeroOneKnapsack(std::tuple<uint32_t, uint32_t> (&items)[N],
                         const uint32_t weight) {
  std::sort(items, items + N, ZeroOneKnapsackItemComparator);
  auto **matrix = new uint32_t *[N];
  for (auto i = 0; i < N; i++) {
    matrix[i] = new unsigned int[weight + 1];
  }

  for (auto i = 0; i < N; i++) {
    matrix[i][0] = 0;
    for (auto j = 1; j <= weight; j++) {
      if (i == 0) {
        matrix[i][j] = std::get<1>(items[i]);
      } else if (j < std::get<0>(items[i])) {
        matrix[i][j] = matrix[i - 1][j];
      } else {
        matrix[i][j] = std::max(
            std::get<1>(items[i]) + matrix[i - 1][j - std::get<0>(items[i])],
            matrix[i - 1][j]);
      }
    }
  }

  auto ret = matrix[N - 1][weight];
  for (auto i = 0; i < N; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
  return ret;
}

namespace test {

void ZeroOneKnapsack_HandlesMultipleKnapsackInput() {
  std::tuple<uint32_t, uint32_t> items[] = {
      std::make_tuple(1, 1), std::make_tuple(4, 5), std::make_tuple(3, 4),
      std::make_tuple(5, 7)};

  EXPECT_EQ(ZeroOneKnapsack(items, 7), 9);
  EXPECT_EQ(ZeroOneKnapsack(items, 10), 13);
  EXPECT_EQ(ZeroOneKnapsack(items, 20), 17);
}

void RunTests() { TEST(ZeroOneKnapsack_HandlesMultipleKnapsackInput); }

}  // namespace test

}  // namespace dynamic_programming
}  // namespace algorithm

int main() {
  std::cout << "-----Running zero-one knapsack tests-----" << std::endl;
  algorithm::dynamic_programming::test::RunTests();
  return 0;
}
#include "utils/test.h"

namespace algorithm {
namespace greedy {

bool FractionalKnapsackItemComparator(const std::tuple<uint32_t, uint32_t> a,
                                      const std::tuple<uint32_t, uint32_t> b) {
  return (std::get<1>(a) / std::get<0>(a)) > (std::get<1>(b) / std::get<0>(b));
}

template <std::size_t N>
uint32_t FractionalKnapsack(std::tuple<uint32_t, uint32_t> (&items)[N],
                            uint32_t weight) {
  std::sort(items, items + N, FractionalKnapsackItemComparator);
  uint32_t maxValue = 0;
  for (std::tuple<uint32_t, uint32_t> item : items) {
    if (weight <= 0) {
      break;
    }
    if (weight < std::get<0>(item)) {
      maxValue += weight * std::get<1>(item) / std::get<0>(item);
      weight = 0;
    } else {
      maxValue += std::get<1>(item);
      weight -= std::get<0>(item);
    }
  }
  return maxValue;
}

namespace test {

void FractionalKnapsack_HandlesMultipleKnapsackInput() {
  std::tuple<uint32_t, uint32_t> items[] = {std::make_tuple(10, 60),
                                            std::make_tuple(30, 120),
                                            std::make_tuple(20, 100)};

  EXPECT_EQ(FractionalKnapsack(items, 50), 240);
  EXPECT_EQ(FractionalKnapsack(items, 60), 280);
  EXPECT_EQ(FractionalKnapsack(items, 30), 160);
  EXPECT_EQ(FractionalKnapsack(items, 5), 30);
}

void RunTests() { TEST(FractionalKnapsack_HandlesMultipleKnapsackInput); }

}  // namespace test

}  // namespace greedy
}  // namespace algorithm

int main() {
  std::cout << "-----Running fractional knapsack tests-----" << std::endl;
  algorithm::greedy::test::RunTests();
  return 0;
}
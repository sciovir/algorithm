#include "fractional_knapsack.cc"

#include "gtest/gtest.h"

namespace algorithm {
namespace greedy {
namespace test {

TEST(FractionalKnapsackTest, HandlesMultipleKnapsackInput) {
  std::tuple<uint32_t, uint32_t> items[] = {std::make_tuple(10, 60),
                                            std::make_tuple(30, 120),
                                            std::make_tuple(20, 100)};

  EXPECT_EQ(FractionalKnapsack(items, 50), 240);
  EXPECT_EQ(FractionalKnapsack(items, 60), 280);
  EXPECT_EQ(FractionalKnapsack(items, 30), 160);
  EXPECT_EQ(FractionalKnapsack(items, 5), 30);
}

}  // namespace test
}  // namespace greedy
}  // namespace algorithm
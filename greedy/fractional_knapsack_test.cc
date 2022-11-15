#include "fractional_knapsack.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

std::tuple<unsigned int, unsigned int> items[] = {std::make_tuple(10, 60),
                                                  std::make_tuple(30, 120),
                                                  std::make_tuple(20, 100)};

TEST(FractionalKnapsackTest, HandlesMultipleKnapsackInput) {
  EXPECT_EQ(greedy::FractionalKnapsack(items, 50), 240);
  EXPECT_EQ(greedy::FractionalKnapsack(items, 60), 280);
  EXPECT_EQ(greedy::FractionalKnapsack(items, 30), 160);
  EXPECT_EQ(greedy::FractionalKnapsack(items, 5), 30);
}

}  // namespace
}  // namespace algorithm

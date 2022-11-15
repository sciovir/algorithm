#pragma once
#include <tuple>

namespace algorithm {
namespace greedy {

bool FractionalKnapsackItemComparator(
    const std::tuple<unsigned int, unsigned int> a,
    const std::tuple<unsigned int, unsigned int> b);

template <size_t N>
unsigned int FractionalKnapsack(
    std::tuple<unsigned int, unsigned int> (&items)[N], unsigned int weight);

}  // namespace greedy
}  // namespace algorithm

#include "fractional_knapsack.cc"
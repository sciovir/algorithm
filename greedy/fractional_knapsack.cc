#include <algorithm>
#include <iostream>

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

}  // namespace greedy
}  // namespace algorithm
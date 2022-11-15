#include "fibonacci.h"

namespace algorithm {
namespace mathematics {

unsigned int BinaryFibonacci(unsigned int n) {
  if (n <= 1) return n;
  return BinaryFibonacci(n - 1) + BinaryFibonacci(n - 2);
}

std::tuple<unsigned int, unsigned int> LinearFibonacci(unsigned int n) {
  if (n <= 1) return std::make_tuple(n, 0);
  std::tuple<unsigned int, unsigned int> ret = LinearFibonacci(n - 1);
  return std::make_tuple(std::get<0>(ret) + std::get<1>(ret), std::get<0>(ret));
}

}  // namespace mathematics
}  // namespace algorithm
#ifndef ALGORITHM_MATHEMATICS_FIBONACCI_H_
#define ALGORITHM_MATHEMATICS_FIBONACCI_H_

#include <iostream>
#include <tuple>

namespace algorithm {
namespace mathematics {

inline unsigned int BinaryFibonacci(unsigned int n) {
  if (n <= 1) return n;
  return BinaryFibonacci(n - 1) + BinaryFibonacci(n - 2);
}

inline std::tuple<unsigned int, unsigned int> LinearFibonacci(unsigned int n) {
  if (n <= 1) return std::make_tuple(n, 0);
  std::tuple<unsigned int, unsigned int> ret = LinearFibonacci(n - 1);
  return std::make_tuple(std::get<0>(ret) + std::get<1>(ret), std::get<0>(ret));
}

}  // namespace mathematics
}  // namespace algorithm

#endif  // ALGORITHM_MATHEMATICS_FIBONACCI_H_

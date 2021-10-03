#ifndef ALGORITHM_MATHEMATICS_FACTORIAL_H_
#define ALGORITHM_MATHEMATICS_FACTORIAL_H_

#include <iostream>

namespace algorithm {
namespace mathematics {

inline int Factorial(int n) {
  if (n == 0) return 1;
  return n * Factorial(n - 1);
}

}  // namespace mathematics
}  // namespace algorithm

#endif  // ALGORITHM_MATHEMATICS_FACTORIAL_H_

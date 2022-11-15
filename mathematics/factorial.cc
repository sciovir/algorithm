#include "factorial.h"

namespace algorithm {
namespace mathematics {

int Factorial(int n) {
  if (n == 0) return 1;
  return n * Factorial(n - 1);
}

}  // namespace mathematics
}  // namespace algorithm
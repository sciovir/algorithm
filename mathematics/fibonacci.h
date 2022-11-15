#ifndef ALGORITHM_MATHEMATICS_FIBONACCI_H_
#define ALGORITHM_MATHEMATICS_FIBONACCI_H_

#include <tuple>

namespace algorithm {
namespace mathematics {

unsigned int BinaryFibonacci(unsigned int n);

std::tuple<unsigned int, unsigned int> LinearFibonacci(unsigned int n);

}  // namespace mathematics
}  // namespace algorithm

#endif  // ALGORITHM_MATHEMATICS_FIBONACCI_H_

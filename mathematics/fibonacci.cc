#include <iostream>
#include <tuple>

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

int main() {
  std::cout << "Binary fibonacci: ";
  std::cout << algorithm::mathematics::BinaryFibonacci(6) << std::endl;  // 8

  std::cout << "Linear fibonacci: ";
  std::cout << std::get<0>(algorithm::mathematics::LinearFibonacci(6))
            << std::endl;  // 8

  return 0;
}

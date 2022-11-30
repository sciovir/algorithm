#include <iostream>

namespace algorithm {
namespace dynamic_programming {

uint32_t CatalanNumber(const uint32_t n) {
  auto *catalan = new uint32_t[n + 1];
  catalan[0] = catalan[1] = 1;
  for (auto i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (auto j = 0; j < i; j++) {
      catalan[i] += catalan[j] * catalan[i - j - 1];
    }
  }
  auto ret = catalan[n];
  delete[] catalan;
  return ret;
}

} // namespace dynamic_programming
} // namespace algorithm

int main() {
  const uint32_t n = 9;
  std::cout << "The " << n << "th catalan number is: ";
  std::cout << algorithm::dynamic_programming::CatalanNumber(n);
  std::cout << std::endl;
  return 0;
}

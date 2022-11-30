#pragma once

#include <stdint.h>

namespace algorithm {
namespace backtracking {

bool PossiblePlace(const int32_t **board, uint32_t n, int32_t x, int32_t y);

bool NQueenRecursive(int32_t **board, uint32_t n, int32_t y);

int32_t **NQueen(int32_t n);

} // namespace backtracking
} // namespace algorithm

#pragma once

#include <stdint.h>

namespace algorithm {
namespace backtracking {

#define CHESS_BOARD_SIZE 8

bool PossibleMove(int32_t **board, int32_t x, int32_t y);

bool KnightTourRecursive(int32_t **board, const int32_t (&x_mv)[8],
                         const int32_t (&y_mv)[8], int32_t mv, int32_t x,
                         int32_t y);

int32_t **KnightTour(uint32_t x, uint32_t y);

} // namespace backtracking
} // namespace algorithm

#pragma once

#include <stdint.h>

namespace algorithm {
namespace backtracking {

#define MAZE_SIZE 4

bool PossibleMove(int32_t **board, int32_t x, int32_t y);

bool RatInMazeRecursive(int32_t **board, int32_t **out, int32_t x, int32_t y,
                        int32_t dx, int32_t dy);

int32_t **RatInMaze(int32_t **board, uint32_t x, uint32_t y, uint32_t dx,
                    uint32_t dy);

} // namespace backtracking
} // namespace algorithm

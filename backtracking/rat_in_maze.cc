#include "rat_in_maze.h"

namespace algorithm {
namespace backtracking {

bool PossibleMove(int32_t **board, int32_t x, int32_t y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && board[x][y] == 1;
}

bool RatInMazeRecursive(int32_t **board, int32_t **out, int32_t x, int32_t y,
                        int32_t dx, int32_t dy) {
  if (PossibleMove(board, x, y)) {
    out[x][y] = 1;
    if (x == dx && y == dy) {
      return true;
    }
    if (RatInMazeRecursive(board, out, x + 1, y, dx, dy) ||
        RatInMazeRecursive(board, out, x, y + 1, dx, dy)) {
      return true;
    }
    out[x][y] = 0;
    return false;
  }

  return false;
}

int32_t **RatInMaze(int32_t **board, uint32_t x, uint32_t y, uint32_t dx,
                    uint32_t dy) {
  auto **out = new int *[MAZE_SIZE];
  for (auto r = 0; r < MAZE_SIZE; r++) {
    out[r] = new int[8];
    for (auto c = 0; c < MAZE_SIZE; c++) {
      out[r][c] = 0;
    }
  }

  if (RatInMazeRecursive(board, out, x, y, dx, dy)) {
    return out;
  } else {
    return nullptr;
  }
}

} // namespace backtracking
} // namespace algorithm

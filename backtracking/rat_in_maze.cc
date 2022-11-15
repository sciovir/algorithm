#include "rat_in_maze.h"

namespace algorithm {
namespace backtracking {

bool PossibleMove(int** board, int x, int y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && board[x][y] == 1;
}

bool RatInMazeRecursive(int** board, int** out, int x, int y, int dx, int dy) {
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

int** RatInMaze(int** board, unsigned int x, unsigned int y, unsigned int dx,
                unsigned int dy) {
  int** out = new int*[MAZE_SIZE];
  for (unsigned int r = 0; r < MAZE_SIZE; r++) {
    out[r] = new int[8];
    for (unsigned int c = 0; c < MAZE_SIZE; c++) {
      out[r][c] = 0;
    }
  }

  if (RatInMazeRecursive(board, out, x, y, dx, dy)) {
    return out;
  } else {
    return nullptr;
  }
}

}  // namespace backtracking
}  // namespace algorithm

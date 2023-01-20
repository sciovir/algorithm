#include "utils/test.h"

namespace algorithm {
namespace backtracking {

#define MAZE_SIZE 4

bool PossibleMove(int32_t** board, int32_t x, int32_t y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && board[x][y] == 1;
}

bool RatInMazeRecursive(int32_t** board, int32_t** out, int32_t x, int32_t y,
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

int32_t** RatInMaze(int32_t** board, uint32_t x, uint32_t y, uint32_t dx,
                    uint32_t dy) {
  auto out = new int32_t*[MAZE_SIZE];
  for (auto r = 0; r < MAZE_SIZE; r++) {
    out[r] = new int32_t[8];
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

namespace test {

void RatInMaze_RatStartFromTopLeftToBottomRight() {
  auto board = new int32_t*[MAZE_SIZE];
  for (auto r = 0; r < MAZE_SIZE; r++) {
    board[r] = new int32_t[8];
    for (auto c = 0; c < MAZE_SIZE; c++) {
      board[r][c] = 0;
    }
  }

  board[0][0] = 1;

  board[1][0] = 1;
  board[1][1] = 1;
  board[1][3] = 1;

  board[2][1] = 1;

  board[3][0] = 1;
  board[3][1] = 1;
  board[3][2] = 1;
  board[3][3] = 1;

  int32_t answer[MAZE_SIZE][MAZE_SIZE] = {
      {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}};

  int32_t** out = RatInMaze(board, 0, 0, MAZE_SIZE - 1, MAZE_SIZE - 1);
  for (auto i = 0; i < MAZE_SIZE; i++) {
    for (auto j = 0; j < MAZE_SIZE; j++) {
      EXPECT_EQ(out[i][j], answer[i][j]);
    }
  }
}

void RunTests() { TEST(RatInMaze_RatStartFromTopLeftToBottomRight); }

}  // namespace test

}  // namespace backtracking
}  // namespace algorithm

int main() {
  std::cout << "-----Running rat in maze tests-----" << std::endl;
  algorithm::backtracking::test::RunTests();
  return 0;
}
#include "rat_in_maze.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(RatInMazeTest, RatStartFromTopLeftToBottomRight) {
  auto **board = new int32_t *[MAZE_SIZE];
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

  auto **out =
      backtracking::RatInMaze(board, 0, 0, MAZE_SIZE - 1, MAZE_SIZE - 1);
  for (auto i = 0; i < MAZE_SIZE; i++) {
    for (auto j = 0; j < MAZE_SIZE; j++) {
      EXPECT_EQ(out[i][j], answer[i][j]);
    }
  }
}

} // namespace
} // namespace algorithm

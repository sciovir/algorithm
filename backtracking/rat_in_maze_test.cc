#include "rat_in_maze.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(RatInMazeTest, RatStartFromTopLeftToBottomRight) {
  int** board = new int*[MAZE_SIZE];
  for (unsigned int r = 0; r < MAZE_SIZE; r++) {
    board[r] = new int[8];
    for (unsigned int c = 0; c < MAZE_SIZE; c++) {
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

  int answer[MAZE_SIZE][MAZE_SIZE] = {
      {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}};

  int** out =
      backtracking::RatInMaze(board, 0, 0, MAZE_SIZE - 1, MAZE_SIZE - 1);
  for (unsigned int i = 0; i < MAZE_SIZE; i++) {
    for (unsigned int j = 0; j < MAZE_SIZE; j++) {
      EXPECT_EQ(out[i][j], answer[i][j]);
    }
  }
}

}  // namespace
}  // namespace algorithm

#include "knight_tour.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(KnightTourTest, KnightStartFromTopLeft) {
  int answer[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE] = {
      {0, 33, 42, 63, 12, 25, 8, 21}, {41, 62, 45, 32, 43, 22, 11, 24},
      {46, 1, 34, 13, 26, 9, 20, 7},  {61, 40, 51, 44, 31, 18, 23, 10},
      {52, 47, 2, 35, 14, 27, 6, 19}, {39, 60, 37, 50, 55, 30, 17, 28},
      {48, 53, 58, 3, 36, 15, 56, 5}, {59, 38, 49, 54, 57, 4, 29, 16}};

  int** board = backtracking::KnightTour(0, 0);
  for (unsigned int i = 0; i < CHESS_BOARD_SIZE; i++) {
    for (unsigned int j = 0; j < CHESS_BOARD_SIZE; j++) {
      EXPECT_EQ(board[i][j], answer[i][j]);
    }
  }
}

}  // namespace
}  // namespace algorithm

#include "utils/test.h"

namespace algorithm {
namespace backtracking {

#define CHESS_BOARD_SIZE 8

bool PossibleMove(int32_t** board, int32_t x, int32_t y) {
  return x >= 0 && x < CHESS_BOARD_SIZE && y >= 0 && y < CHESS_BOARD_SIZE &&
         board[x][y] == -1;
}

bool KnightTourRecursive(int32_t** board, const int32_t (&x_mv)[8],
                         const int32_t (&y_mv)[8], int32_t mv, int32_t x,
                         int32_t y) {
  if (mv == CHESS_BOARD_SIZE * CHESS_BOARD_SIZE) {
    return true;
  }

  int32_t x_next, y_next;

  for (auto i = 0; i < 8; i++) {
    x_next = x + x_mv[i];
    y_next = y + y_mv[i];

    if (PossibleMove(board, x_next, y_next)) {
      board[x_next][y_next] = mv;
      if (KnightTourRecursive(board, x_mv, y_mv, mv + 1, x_next, y_next)) {
        return true;
      } else {
        board[x_next][y_next] = -1;
      }
    }
  }

  return false;
}

int32_t** KnightTour(uint32_t x, uint32_t y) {
  auto board = new int32_t*[CHESS_BOARD_SIZE];
  for (auto r = 0; r < CHESS_BOARD_SIZE; r++) {
    board[r] = new int32_t[CHESS_BOARD_SIZE];
    for (auto c = 0; c < CHESS_BOARD_SIZE; c++) {
      board[r][c] = -1;
    }
  }

  int32_t x_move[] = {2, 1, -1, -2, -2, -1, 2, 1};
  int32_t y_move[] = {1, 2, 2, 1, -1, -2, -1, -2};

  board[0][0] = 0;
  if (KnightTourRecursive(board, x_move, y_move, 1, x, y)) {
    return board;
  } else {
    return nullptr;
  }
}

namespace test {

void KnightTour_KnightStartFromTopLeft() {
  int32_t answer[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE] = {
      {0, 33, 42, 63, 12, 25, 8, 21}, {41, 62, 45, 32, 43, 22, 11, 24},
      {46, 1, 34, 13, 26, 9, 20, 7},  {61, 40, 51, 44, 31, 18, 23, 10},
      {52, 47, 2, 35, 14, 27, 6, 19}, {39, 60, 37, 50, 55, 30, 17, 28},
      {48, 53, 58, 3, 36, 15, 56, 5}, {59, 38, 49, 54, 57, 4, 29, 16}};

  auto board = KnightTour(0, 0);
  for (auto i = 0; i < CHESS_BOARD_SIZE; i++) {
    for (auto j = 0; j < CHESS_BOARD_SIZE; j++) {
      EXPECT_EQ(board[i][j], answer[i][j]);
    }
  }
}

void RunTests() { TEST(KnightTour_KnightStartFromTopLeft); }

}  // namespace test

}  // namespace backtracking
}  // namespace algorithm

int main() {
  std::cout << "-----Running knight tour tests-----" << std::endl;
  algorithm::backtracking::test::RunTests();
  return 0;
}
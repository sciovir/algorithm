#include "knight_tour.h"

namespace algorithm {
namespace backtracking {

bool PossibleMove(int32_t **board, int32_t x, int32_t y) {
  return x >= 0 && x < CHESS_BOARD_SIZE && y >= 0 && y < CHESS_BOARD_SIZE &&
         board[x][y] == -1;
}

bool KnightTourRecursive(int32_t **board, const int32_t (&x_mv)[8],
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

int32_t **KnightTour(uint32_t x, uint32_t y) {
  auto **board = new int *[CHESS_BOARD_SIZE];
  for (auto r = 0; r < CHESS_BOARD_SIZE; r++) {
    board[r] = new int[CHESS_BOARD_SIZE];
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

} // namespace backtracking
} // namespace algorithm

"""
Knight's tour problem
"""
import unittest


def knight_tour(board_size: int, x: int, y: int) -> list[list[int]]:
    if x < 0 or y < 0:
        raise ValueError("x and y must be positive")

    board: list[list[int]] = [[-1 for _ in range(board_size)] for _ in range(board_size)]
    x_mv: list[int] = [2, 1, -1, -2, -2, -1, 2, 1]
    y_mv: list[int] = [1, 2, 2, 1, -1, -2, -1, -2]

    board[0][0] = 0
    if knight_tour_recursive(board, x_mv, y_mv, 1, x, y):
        return board

    return []


def knight_tour_recursive(board: list[list[int]], x_mv: list[int],
                          y_mv: list[int], mv: int, x: int, y: int) -> bool:
    if mv == len(board) * len(board):
        return True

    for i in range(len(board)):
        x_nxt = x + x_mv[i]
        y_nxt = y + y_mv[i]

        if possible_move(board, x_nxt, y_nxt):
            board[x_nxt][y_nxt] = mv
            if knight_tour_recursive(board, x_mv, y_mv, mv + 1, x_nxt, y_nxt):
                return True
            board[x_nxt][y_nxt] = -1

    return False


def possible_move(board: list[list[int]], x: int, y: int) -> bool:
    return 0 <= x < len(board) and 0 <= y < len(board) and board[x][y] == -1


class TestKnightTour(unittest.TestCase):

    def test_knight_start_from_top_left(self):
        answer: list[list[int]] = [
            [0, 33, 42, 63, 12, 25, 8, 21],
            [41, 62, 45, 32, 43, 22, 11, 24],
            [46, 1, 34, 13, 26, 9, 20, 7],
            [61, 40, 51, 44, 31, 18, 23, 10],
            [52, 47, 2, 35, 14, 27, 6, 19],
            [39, 60, 37, 50, 55, 30, 17, 28],
            [48, 53, 58, 3, 36, 15, 56, 5],
            [59, 38, 49, 54, 57, 4, 29, 16]
        ]
        result: list[list[int]] = knight_tour(len(answer), 0, 0)
        for i in range(len(result)):
            self.assertCountEqual(result[i], answer[i])
            self.assertListEqual(result[i], answer[i])


if __name__ == '__main__':
    unittest.main()

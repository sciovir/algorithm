"""
N Queen problem
"""
import unittest


def n_queen(board_size: int) -> list[list[int]]:
    if board_size < 1:
        raise ValueError('board size must be positive')

    board: list[list[int]] = [[0 for _ in range(board_size)] for _ in range(board_size)]
    if n_queen_recursive(board, 0):
        return board

    return []


def n_queen_recursive(board: list[list[int]], y: int) -> bool:
    if y >= len(board):
        return True

    for i in range(len(board)):
        if possible_place(board, i, y):
            board[i][y] = 1
            if n_queen_recursive(board, y + 1):
                return True
            board[i][y] = 0

    return False


def possible_place(board: list[list[int]], x: int, y: int) -> bool:
    for i in range(len(board)):
        if board[x][i] == 1 or board[i][y] == 1:
            return False

    i, j = x - 1, y - 1
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    i, j = x + 1, y + 1
    while i < len(board) and j < len(board):
        if board[i][j] == 1:
            return False
        i += 1
        j += 1

    i, j = x + 1, y - 1
    while i < len(board) and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    i, j = x - 1, y + 1
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True


class TestNQueen(unittest.TestCase):

    def test_handles_variety_amount_of_queens(self):
        answer: list[list[int]] = [
            [0, 0, 1, 0],
            [1, 0, 0, 0],
            [0, 0, 0, 1],
            [0, 1, 0, 0]
        ]
        result: list[list[int]] = n_queen(4)
        for i in range(len(result)):
            self.assertCountEqual(result[i], answer[i])
            self.assertListEqual(result[i], answer[i])

        answer = [
            [1, 0, 0, 0, 0],
            [0, 0, 0, 1, 0],
            [0, 1, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [0, 0, 1, 0, 0]
        ]

        result = n_queen(5)
        for i in range(len(result)):
            self.assertCountEqual(result[i], answer[i])
            self.assertListEqual(result[i], answer[i])


if __name__ == '__main__':
    unittest.main()

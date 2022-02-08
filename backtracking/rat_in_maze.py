"""
Rat in maze problem
"""
import unittest


def rat_in_maze(board: list[list[int]], x: int, y: int, dx: int, dy: int) -> list[list[int]]:
    out: list[list[int]] = [[0 for _ in range(len(board))] for _ in range(len(board))]
    if rat_in_maze_recursive(board, out, x, y, dx, dy):
        return out
    return []


def rat_in_maze_recursive(board: list[list[int]], out: list[list[int]],
                          x: int, y: int, dx: int, dy: int) -> bool:
    if possible_move(board, x, y):
        out[x][y] = 1
        if x == dx and y == dy:
            return True

        if rat_in_maze_recursive(board, out, x + 1, y, dx, dy) or \
            rat_in_maze_recursive(board, out, x, y + 1, dx, dy):
            return True
        out[x][y] = 0

    return False


def possible_move(board: list[list[int]], x: int, y: int) -> bool:
    return 0 <= x < len(board) and 0 <= y <= len(board) and board[x][y] == 1


class TestRatInMaze(unittest.TestCase):

    def test_rat_run_from_top_left_to_bottom_right(self):
        board: list[list[int]] = [
            [1, 0, 0, 0],
            [1, 1, 0, 1],
            [0, 1, 0, 0],
            [1, 1, 1, 1]
        ]
        answer: list[list[int]] = [
            [1, 0, 0, 0],
            [1, 1, 0, 0],
            [0, 1, 0, 0],
            [0, 1, 1, 1]
        ]

        result: list[list[int]] = rat_in_maze(board, 0, 0, len(board) - 1, len(board) - 1)
        for i in range(len(result)):
            self.assertCountEqual(result[i], answer[i])
            self.assertListEqual(result[i], answer[i])


if __name__ == '__main__':
    unittest.main()

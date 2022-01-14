"""
nth Catalan number
"""
import unittest


def catalan_number(n: int) -> int:
    if n < 0:
        raise ValueError("n must be positive")

    catalan: list[int] = [0] * (n + 1)
    catalan[0] = catalan[1] = 1

    for i in range(2, n + 1):
        for j in range(0, i):
            catalan[i] += catalan[j] * catalan[i - j - 1]

    return catalan[n]


class TestCatalanNumber(unittest.TestCase):

    def test_multiple_valid_input(self):
        self.assertEqual(catalan_number(2), 2)
        self.assertEqual(catalan_number(3), 5)
        self.assertEqual(catalan_number(4), 14)
        self.assertEqual(catalan_number(8), 1430)
        self.assertEqual(catalan_number(9), 4862)

    def test_invalid_input(self):
        with self.assertRaises(ValueError):
            catalan_number(-1)


if __name__ == '__main__':
    unittest.main()

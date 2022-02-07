"""
nth Fibonacci number
"""
import unittest


def fibonacci_number(n: int) -> int:
    if n < 0:
        raise ValueError("n must be positive")

    fibonacci: list[int] = [0] * (n + 1)
    fibonacci[0] = 0
    fibonacci[1] = 1

    for i in range(2, n + 1):
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]

    return fibonacci[n]


class TestFibonacciNumber(unittest.TestCase):

    def test_multiple_valid_input(self):
        self.assertEqual(fibonacci_number(2), 1)
        self.assertEqual(fibonacci_number(3), 2)
        self.assertEqual(fibonacci_number(4), 3)
        self.assertEqual(fibonacci_number(8), 21)
        self.assertEqual(fibonacci_number(9), 34)

    def test_invalid_input(self):
        with self.assertRaises(ValueError):
            fibonacci_number(-1)


if __name__ == '__main__':
    unittest.main()

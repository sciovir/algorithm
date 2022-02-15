"""
Factorial of n
"""
import unittest


def factorial(n: int) -> int:
    return 1 if n < 1 else n * factorial(n - 1)


class TestCatalanNumber(unittest.TestCase):

    def test_multiple_valid_input(self):
        self.assertEqual(factorial(1), 1)
        self.assertEqual(factorial(2), 2)
        self.assertEqual(factorial(3), 6)
        self.assertEqual(factorial(6), 720)
        self.assertEqual(factorial(8), 40320)


if __name__ == '__main__':
    unittest.main()

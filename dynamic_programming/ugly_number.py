"""
nth ugly number
"""
import unittest


def ugly_number(n: int) -> int:
    if n < 0:
        raise ValueError("n must be positive")

    ugly_numbers: list[int] = [0] * n
    i2 = i3 = i5 = 0
    multiplication_2, multiplication_3, multiplication_5 = 2, 3, 5
    next_ugly_number = 1
    ugly_numbers[0] = next_ugly_number

    for i in range(1, n):
        next_ugly_number = min(
            multiplication_2, min(multiplication_3, multiplication_5)
        )
        ugly_numbers[i] = next_ugly_number

        if multiplication_2 == next_ugly_number:
            i2 += 1
            multiplication_2 = ugly_numbers[i2] * 2
        if multiplication_3 == next_ugly_number:
            i3 += 1
            multiplication_3 = ugly_numbers[i3] * 3
        if multiplication_5 == next_ugly_number:
            i5 += 1
            multiplication_5 = ugly_numbers[i5] * 5

    return next_ugly_number


class TestUglyNumber(unittest.TestCase):
    def test_multiple_valid_input(self):
        self.assertEqual(ugly_number(2), 2)
        self.assertEqual(ugly_number(3), 3)
        self.assertEqual(ugly_number(4), 4)
        self.assertEqual(ugly_number(8), 9)
        self.assertEqual(ugly_number(9), 10)

    def test_invalid_input(self):
        with self.assertRaises(ValueError):
            ugly_number(-1)


if __name__ == "__main__":
    unittest.main()

"""
nth Fibonacci number
"""
import unittest


def fibonacci(n: int) -> tuple[int, int]:
    if n < 2:
        return (
            n,
            0,
        )
    ret: tuple[int, int] = fibonacci(n - 1)
    return (
        ret[0] + ret[1],
        ret[0],
    )


class TestCatalanNumber(unittest.TestCase):
    def test_multiple_valid_input(self):
        self.assertEqual(fibonacci(1)[0], 1)
        self.assertEqual(fibonacci(2)[0], 1)
        self.assertEqual(fibonacci(3)[0], 2)
        self.assertEqual(fibonacci(6)[0], 8)


if __name__ == "__main__":
    unittest.main()

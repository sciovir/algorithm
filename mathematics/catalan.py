"""
nth Catalan number
"""
import unittest


def catalan(n: int) -> int:
    return 1 if n < 2 else sum([catalan(i) * catalan(n - i - 1) for i in range(n)])


class TestCatalanNumber(unittest.TestCase):
    def test_multiple_valid_input(self):
        self.assertEqual(catalan(2), 2)
        self.assertEqual(catalan(3), 5)
        self.assertEqual(catalan(4), 14)
        self.assertEqual(catalan(8), 1430)
        self.assertEqual(catalan(9), 4862)


if __name__ == "__main__":
    unittest.main()

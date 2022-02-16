"""
Maximum sub-array problem
"""
import sys
import unittest


def max_crossing_subarray(array: list[int], lo: int, mi: int, hi: int) -> tuple[int, int, int]:
    left_sum = right_sum = -sys.maxsize - 1
    tmp_sum, left_max, right_max = 0, mi, mi + 1

    for i in range(mi, lo - 1, -1):
        tmp_sum += array[i]
        if tmp_sum > left_sum:
            left_sum = tmp_sum
            left_max = i

    tmp_sum = 0
    for i in range(mi + 1, hi + 1):
        tmp_sum += array[i]
        if tmp_sum > right_sum:
            right_sum = tmp_sum
            right_max = i

    tmp_sum = left_sum + right_sum
    if left_sum > tmp_sum and left_sum > right_sum:
        return left_max, mi, left_sum,
    elif right_sum > left_sum and right_sum > tmp_sum:
        return mi + 1, right_max, right_sum,
    return left_max, right_max, tmp_sum,


def maximum_subarray(array: list[int], lo: int, hi: int) -> tuple[int, int, int]:
    if lo > hi:
        raise ValueError('Low index must be less than or equal high index')

    if lo == hi:
        return lo, hi, array[lo]
    mi: int = (lo + hi) // 2

    left_tup = maximum_subarray(array, lo, mi)
    right_tup = maximum_subarray(array, mi + 1, hi)
    crossing_tup = max_crossing_subarray(array, lo, mi, hi)

    if left_tup[2] > right_tup[2] and left_tup[2] > crossing_tup[2]:
        return left_tup
    elif right_tup[2] > left_tup[2] and right_tup[2] > crossing_tup[2]:
        return right_tup
    return crossing_tup


class TestMaximumSubarray(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestMaximumSubarray, self).__init__(*args, **kwargs)
        self.array: list[int] = [12, -2, -23, 18, -1, -14, -21, 16, 19, -5, 10, -3, -20, 13, -4, -7]

    def test_valid_arguments(self):
        start_index, end_index, max_sum = maximum_subarray(self.array, 0, len(self.array) - 1)
        self.assertEqual(start_index, 7)
        self.assertEqual(end_index, 10)
        self.assertEqual(max_sum, 40)

    def test_invalid_arguments(self):
        with self.assertRaises(ValueError):
            maximum_subarray(self.array, len(self.array) - 1, 0)


if __name__ == '__main__':
    unittest.main()

"""
Radix Sort
"""
import unittest


def radix_sort(array: list[int]):
    if not all(element >= 0 for element in array):
        raise ValueError('Only accept non-negative integer array')

    max_element, position = max(array), 1
    while max_element // position > 0:
        digit_counting_sort(array, position)
        position *= 10


def digit_counting_sort(array: list[int], position: int):
    copy = array.copy()
    auxiliary = [0] * 10

    for element in array:
        auxiliary[(element // position) % 10] += 1
    for i in range(1, 10):
        auxiliary[i] += auxiliary[i - 1]

    for i in range(len(copy) - 1, -1, -1):
        array[auxiliary[(copy[i] // position) % 10] - 1] = copy[i]
        auxiliary[(copy[i] // position) % 10] -= 1


class TestCountingSort(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestCountingSort, self).__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]

    def test_handles_valid_input(self):
        radix_sort(self.integers)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])

    def test_invalid_input(self):
        mixed_integers = [12, -2, -23, 18, -1, -14, -21, 16, 19]
        with self.assertRaises(ValueError):
            radix_sort(mixed_integers)


if __name__ == '__main__':
    unittest.main()

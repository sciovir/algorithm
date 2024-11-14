import copy


def quick_sort(collection: list, use_hoare: bool = True) -> list:
    """
    An implementation of Quick Sort algorithm.

    :param collection: a mutable collection of comparable items
    :return: a sorted collection

    Examples:
    >>> quick_sort([6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3])
    [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40]

    >>> quick_sort(['c', 'java', 'cpp', 'python', 'go', 'sql', 'swift'])
    ['c', 'cpp', 'go', 'java', 'python', 'sql', 'swift']

    >>> quick_sort([5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9])
    [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5]

    >>> quick_sort([6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3], False)
    [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40]

    >>> quick_sort(['c', 'java', 'cpp', 'python', 'go', 'sql', 'swift'], False)
    ['c', 'cpp', 'go', 'java', 'python', 'sql', 'swift']

    >>> quick_sort([5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9], False)
    [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5]

    >>> import random
    >>> collection = random.sample(range(-50, 50), 100)
    >>> quick_sort(collection) == sorted(collection)
    True
    """
    result = copy.deepcopy(collection)
    _sort(result, 0, len(result) - 1, use_hoare)
    return result


def _sort(collection: list, lo: int, hi: int, use_hoare: bool):
    if lo < hi and lo >= 0 and hi >= 0:
        pivot_index = (
            _hoare_partition_scheme(collection, lo, hi)
            if use_hoare
            else _lomuto_partition_scheme(collection, lo, hi)
        )
        _sort(collection, lo, pivot_index if use_hoare else pivot_index - 1, use_hoare)
        _sort(collection, pivot_index + 1, hi, use_hoare)


def _hoare_partition_scheme(collection: list, lo: int, hi: int) -> int:
    pivot = collection[lo]
    left = lo
    right = hi

    while True:
        while collection[left] < pivot:
            left += 1

        while collection[right] > pivot:
            right -= 1

        if left >= right:
            return right

        collection[left], collection[right] = collection[right], collection[left]


def _lomuto_partition_scheme(collection: list, lo: int, hi: int) -> int:
    pivot = collection[hi]
    temp = lo

    for index in range(lo, hi):
        if collection[index] <= pivot:
            collection[temp], collection[index] = collection[index], collection[temp]
            temp += 1

    collection[temp], collection[hi] = collection[hi], collection[temp]
    return temp


if __name__ == "__main__":
    import doctest

    doctest.testmod()

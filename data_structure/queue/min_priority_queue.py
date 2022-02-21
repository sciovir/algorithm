"""
Min Priority Queue
"""
import unittest
from typing import TypeVar, Generator, Any

from data_structure.heap.min_heap import MinHeap

T = TypeVar('T')


class MinPriorityQueue(MinHeap[T]):

    def __init__(self, array: list[T], cap: int = 10):
        super().__init__([], cap)
        if array:
            for i in range(len(array)):
                self.insert(array[i])
            self._cap = max(len(array), cap)
            self._size = len(array)

    def __iter__(self) -> Generator[T, Any, None]:
        if not self.is_empty():
            for i in range(self._size):
                yield self._data[i]

    def __repr__(self) -> str:
        return ','.join([f'({v} [{i}])' for i, v in enumerate(self)])

    def minimum(self) -> T:
        if self.is_empty():
            raise RuntimeError('Priority queue underflow, can not get minimum')
        return self._data[0]

    def extract_min(self) -> T:
        if self.is_empty():
            raise RuntimeError('Priority queue underflow, can not extract minimum')
        return self.remove(0)

    def decrease_key(self, index: int, key: T):
        if key > self._data[index]:
            raise RuntimeError('New key is larger than current key')

        self._data[index] = key
        while index > 0 and self._data[self._parent(index)] > self._data[index]:
            self.swap(index, self._parent(index))
            index = self._parent(index)

    def insert(self, value: T):
        if self.is_full():
            raise RuntimeError('Priority queue overflow, can not insert')
        self._data[self._size] = value
        self.decrease_key(self._size, value)
        self._size += 1


class TestMinPriorityQueue(unittest.TestCase):

    def test_integer_min_priority_queue(self):
        pri_q: MinPriorityQueue[int] = MinPriorityQueue([6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3], 13)

        self.assertFalse(pri_q.is_empty())
        self.assertEqual(pri_q.size, 11)

        pri_q.insert(18)
        pri_q.insert(6)

        self.assertEqual(pri_q.size, 13)
        self.assertListEqual([e for e in pri_q],
                             [2, 3, 6, 8, 5, 6, 40, 26, 22, 32, 9, 18, 10])

        with self.assertRaises(RuntimeError):
            pri_q.insert(19)

        self.assertEqual(pri_q.minimum(), 2)
        pri_q.decrease_key(8, 1)
        self.assertEqual(pri_q.minimum(), 1)

        self.assertEqual(pri_q.extract_min(), 1)
        self.assertEqual(pri_q.size, 12)

        pri_q.insert(1)
        self.assertListEqual([e for e in pri_q],
                             [1, 3, 2, 8, 5, 6, 40, 26, 10, 32, 9, 18, 6])

        self.assertEqual(pri_q.extract_min(), 1)
        self.assertEqual(pri_q.extract_min(), 2)
        self.assertEqual(pri_q.extract_min(), 3)
        self.assertEqual(pri_q.extract_min(), 5)
        self.assertEqual(pri_q.extract_min(), 6)
        self.assertEqual(pri_q.extract_min(), 6)
        self.assertEqual(pri_q.extract_min(), 8)
        self.assertEqual(pri_q.extract_min(), 9)
        self.assertEqual(pri_q.extract_min(), 10)
        self.assertEqual(pri_q.extract_min(), 18)
        self.assertEqual(pri_q.extract_min(), 26)
        self.assertEqual(pri_q.extract_min(), 32)
        self.assertEqual(pri_q.extract_min(), 40)

        with self.assertRaises(RuntimeError):
            pri_q.extract_min()


if __name__ == '__main__':
    unittest.main()

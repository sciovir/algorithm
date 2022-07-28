"""
Min Priority Queue
"""
import unittest
from typing import TypeVar, Generator, Any

from data_structure.heap.max_heap import MaxHeap

T = TypeVar("T")


class MaxPriorityQueue(MaxHeap[T]):
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
        return ",".join([f"({v} [{i}])" for i, v in enumerate(self)])

    def maximum(self) -> T:
        if self.is_empty():
            raise RuntimeError("Priority queue underflow, can not get maximum")
        return self._data[0]

    def extract_max(self) -> T:
        if self.is_empty():
            raise RuntimeError("Priority queue underflow, can not extract maximum")
        return self.remove(0)

    def increase_key(self, index: int, key: T):
        if key < self._data[index]:
            raise RuntimeError("New key is smaller than current key")

        self._data[index] = key
        while index > 0 and self._data[self._parent(index)] < self._data[index]:
            self.swap(index, self._parent(index))
            index = self._parent(index)

    def insert(self, value: T):
        if self.is_full():
            raise RuntimeError("Priority queue overflow, can not insert")
        self._data[self._size] = value
        self.increase_key(self._size, value)
        self._size += 1


class TestMaxPriorityQueue(unittest.TestCase):
    def test_integer_min_priority_queue(self):
        pri_q: MaxPriorityQueue[int] = MaxPriorityQueue(
            [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3], 13
        )

        self.assertFalse(pri_q.is_empty())
        self.assertEqual(pri_q.size, 11)

        pri_q.insert(18)
        pri_q.insert(6)

        self.assertEqual(pri_q.size, 13)
        self.assertListEqual(
            [e for e in pri_q], [40, 32, 26, 10, 22, 18, 8, 6, 5, 9, 3, 2, 6]
        )

        with self.assertRaises(RuntimeError):
            pri_q.insert(19)

        self.assertEqual(pri_q.maximum(), 40)
        pri_q.increase_key(8, 41)
        self.assertEqual(pri_q.maximum(), 41)

        self.assertEqual(pri_q.extract_max(), 41)
        self.assertEqual(pri_q.size, 12)

        pri_q.insert(41)
        self.assertListEqual(
            [e for e in pri_q], [41, 32, 40, 10, 22, 26, 8, 6, 6, 9, 3, 2, 18]
        )

        self.assertEqual(pri_q.extract_max(), 41)
        self.assertEqual(pri_q.extract_max(), 40)
        self.assertEqual(pri_q.extract_max(), 32)
        self.assertEqual(pri_q.extract_max(), 26)
        self.assertEqual(pri_q.extract_max(), 22)
        self.assertEqual(pri_q.extract_max(), 18)
        self.assertEqual(pri_q.extract_max(), 10)
        self.assertEqual(pri_q.extract_max(), 9)
        self.assertEqual(pri_q.extract_max(), 8)
        self.assertEqual(pri_q.extract_max(), 6)
        self.assertEqual(pri_q.extract_max(), 6)
        self.assertEqual(pri_q.extract_max(), 3)
        self.assertEqual(pri_q.extract_max(), 2)

        with self.assertRaises(RuntimeError):
            pri_q.extract_max()


if __name__ == "__main__":
    unittest.main()

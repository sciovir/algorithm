"""
Heap
"""
from abc import ABC, abstractmethod
from typing import TypeVar, Generic, Generator, Any

T = TypeVar("T")


class AbstractHeap(ABC, Generic[T]):
    def __init__(self, cap: int = 100):
        self._data: list[T] = [None] * cap
        self._cap = cap
        self._size = 0

    def __iter__(self) -> Generator[T, Any, None]:
        if self._size == 1:
            yield self._data[0]
        elif not self.is_empty():
            for i in range(self._size // 2):
                if i == 0:
                    yield self._data[i]
                if 0 < self._left(i) < self.size:
                    yield self._data[self._left(i)]
                if 0 < self._right(i) < self.size:
                    yield self._data[self._right(i)]

    def __repr__(self) -> str:
        break_line, ret = 0, ""
        for i, v in enumerate(self):
            ret += f"[{v}]({i})"
            if i == break_line:
                ret += "\n"
                break_line = 2 * break_line + 2
            else:
                ret += " "
        return ret

    @property
    def size(self) -> int:
        return self._size

    @size.setter
    def size(self, size: int):
        self._size = size

    def build_heap(self):
        for i in range(self._size // 2, -1, -1):
            self.heapify(i)

    @abstractmethod
    def heapify(self, index: int):
        pass

    @abstractmethod
    def insert(self, value: T):
        pass

    def remove(self, index: int) -> T:
        if self.is_empty():
            raise RuntimeError("Heap underflow")

        if index >= self._size:
            raise RuntimeError("Invalid index")

        removed = self._data[index]
        self._size -= 1
        self._data[index] = self._data[self._size]
        self._data[self._size] = None

        self.heapify(index)
        return removed

    def is_empty(self) -> bool:
        return self._size == 0

    def is_full(self) -> bool:
        return self._size == self._cap

    def swap(self, i: int, j: int):
        self._data[i], self._data[j] = self._data[j], self._data[i]

    @staticmethod
    def _parent(index: int) -> int:
        return (index - 1) // 2

    @staticmethod
    def _left(index: int) -> int:
        return 2 * index + 1

    @staticmethod
    def _right(index: int) -> int:
        return 2 * index + 2

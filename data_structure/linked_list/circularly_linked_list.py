"""
Circularly Linked List
"""
from __future__ import annotations

import unittest
from typing import Generator, Any


class CircularlyLinkedList:
    class Node:
        def __init__(self, data: Any, nxt: CircularlyLinkedList.Node | None = None):
            self._data = data
            self._nxt = nxt

        def __repr__(self) -> str:
            return f"[{self._data}]->"

        @property
        def data(self) -> Any:
            return self._data

        @data.setter
        def data(self, data):
            self._data = data

        @property
        def nxt(self) -> CircularlyLinkedList.Node | None:
            return self._nxt

        @nxt.setter
        def nxt(self, nxt):
            self._nxt = nxt

    def __init__(self, tail: CircularlyLinkedList.Node | None = None, size: int = 0):
        self._tail = tail
        self._size = size

    def __iter__(self) -> Generator[Node | None, Any, None]:
        if not self.is_empty():
            tmp: CircularlyLinkedList.Node | None = self._tail.nxt
            while True:
                yield tmp
                tmp = tmp.nxt

                if tmp is self._tail.nxt:
                    break

    def __repr__(self) -> str:
        return "".join([str(node) for node in self])

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._tail is None

    def rotate(self):
        self._tail = self._tail.nxt

    def search(self, data: Any) -> bool:
        if self.is_empty():
            return False

        tmp: CircularlyLinkedList.Node | None = self._tail.nxt
        while True:
            if tmp.data == data:
                return True
            tmp = tmp.nxt

            if tmp is self._tail.nxt:
                break

        return False

    def insert(self, data: Any):
        node = CircularlyLinkedList.Node(data)
        if self.is_empty():
            self._tail = node
            self._tail.nxt = self._tail
        else:
            node.nxt = self._tail.nxt
            self._tail.nxt = node
        self._size += 1
        self.rotate()

    def remove(self, data: Any) -> Any:
        if self.is_empty():
            raise RuntimeError("List is empty, can not remove")

        old: CircularlyLinkedList.Node | None = self._tail.nxt
        prev: CircularlyLinkedList.Node | None
        while True:
            prev = old
            old = old.nxt

            if old is self._tail.nxt or old.data == data:
                break

        if not old or old.data != data:
            raise RuntimeError("Node is not exist in this list")

        removed = old.data
        if self._tail.nxt is self._tail:
            self._tail.nxt = None
            self._tail = None
        else:
            prev.nxt = old.nxt
            if old is self._tail:
                self._tail = prev

        self._size -= 1
        return removed


class TestCircularlyLinkedList(unittest.TestCase):
    def test_integer_linked_list(self):
        linked_list: CircularlyLinkedList = CircularlyLinkedList()

        self.assertTrue(linked_list.is_empty())
        self.assertEqual(linked_list.size, 0)

        linked_list.insert(8)
        linked_list.insert(12)
        linked_list.insert(6)
        linked_list.insert(10)

        self.assertFalse(linked_list.is_empty())
        self.assertListEqual(
            [node.data for node in linked_list if node], [8, 12, 6, 10]
        )

        self.assertTrue(linked_list.search(8))
        self.assertFalse(linked_list.search(9))

        linked_list.remove(10)
        self.assertListEqual([node.data for node in linked_list if node], [8, 12, 6])
        linked_list.remove(6)
        self.assertListEqual([node.data for node in linked_list if node], [8, 12])

        with self.assertRaises(RuntimeError):
            linked_list.remove(9)

        linked_list.remove(8)
        self.assertListEqual([node.data for node in linked_list if node], [12])
        linked_list.remove(12)
        self.assertListEqual([node.data for node in linked_list if node], [])

        with self.assertRaises(RuntimeError):
            linked_list.remove(9)


if __name__ == "__main__":
    unittest.main()

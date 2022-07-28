"""
Hash Table Separate Chaining
"""
from __future__ import annotations

import unittest
from typing import TypeVar, Generic, Generator, Any

K = TypeVar("K")
V = TypeVar("V")


class HashTable(Generic[K, V]):
    class Node:
        def __init__(self, key: K, value: V, nxt: HashTable.Node = None) -> None:
            self._key = key
            self._value = value
            self._nxt = nxt

        def __repr__(self) -> str:
            return f"[{self._key}: {self._value}]"

        @property
        def key(self) -> K:
            return self._key

        @key.setter
        def key(self, key) -> None:
            self._key = key

        @property
        def value(self) -> V:
            return self._value

        @value.setter
        def value(self, value) -> None:
            self._value = value

        @property
        def nxt(self) -> HashTable.Node:
            return self._nxt

        @nxt.setter
        def nxt(self, nxt):
            self._nxt = nxt

    def __init__(self, slots: int = 10):
        self._buckets: list[HashTable.Node | None] = [None] * slots
        self._keys: list[K] = []
        self._slots = slots
        self._size = 0

    def __iter__(self) -> Generator[tuple[K, V], Any, None]:
        if not self.is_empty():
            for key in self._keys:
                yield key, self.get(key),

    def __repr__(self) -> str:
        return ", ".join([f"[{k}: {v}]" for k, v in self])

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._size == 0

    @property
    def keys(self) -> list[K]:
        return self._keys.copy()

    def _hashing(self, key: K) -> int:
        hash_key = int(key) % self._slots
        if hash_key < 0:
            hash_key += self._slots
        return hash_key

    def get(self, key: K) -> V:
        hash_key = self._hashing(key)
        node = self._buckets[hash_key]
        while node and node.key != key:
            node = node.nxt

        if node is None:
            raise RuntimeError("Key is not exist in hash table")
        return node.value

    def insert(self, key: K, value: V) -> None:
        hash_key = self._hashing(key)
        node = HashTable.Node(key, value)

        if self._buckets[hash_key] is None:
            self._buckets[hash_key] = node
        else:
            tmp = self._buckets[hash_key]
            if tmp.key == key:
                raise RuntimeError("Key is already exist")
            while tmp.nxt:
                if tmp.key == key:
                    raise RuntimeError("Key is already exist")
                tmp = tmp.nxt
            tmp.nxt = node

        self._keys.append(key)
        self._size += 1

    def remove(self, key: K) -> V:
        hash_key = self._hashing(key)
        node = self._buckets[hash_key]
        prev: HashTable.Node | None = None

        while node and node.key != key:
            prev = node
            node = node.nxt

        if node is None:
            raise RuntimeError("Key is not exist in this hash table")

        removed = node.value
        if node is self._buckets[hash_key]:
            self._buckets[hash_key] = node.nxt
        elif prev is None:
            self._buckets[hash_key] = None
        else:
            prev.nxt = node.nxt

        node.nxt = None
        self._keys.remove(key)
        self._size -= 1
        return removed


class TestHashTableSeparateChaining(unittest.TestCase):
    def test_integer_string_hash_table(self):
        hash_table: HashTable[int, str] = HashTable()

        self.assertTrue(hash_table.is_empty())
        self.assertEqual(hash_table.size, 0)

        hash_table.insert(18, "Cat")
        hash_table.insert(60, "Dog")
        hash_table.insert(20, "Dolphin")
        hash_table.insert(96, "Mouse")
        hash_table.insert(71, "Rabbit")
        hash_table.insert(22, "Snake")

        self.assertFalse(hash_table.is_empty())
        self.assertListEqual([k for k, _ in hash_table], [18, 60, 20, 96, 71, 22])
        self.assertListEqual(
            [v for _, v in hash_table],
            ["Cat", "Dog", "Dolphin", "Mouse", "Rabbit", "Snake"],
        )

        self.assertEqual(hash_table.get(60), "Dog")
        self.assertEqual(hash_table.get(96), "Mouse")

        self.assertEqual(hash_table.remove(18), "Cat")
        self.assertListEqual([k for k, _ in hash_table], [60, 20, 96, 71, 22])
        self.assertListEqual(
            [v for _, v in hash_table], ["Dog", "Dolphin", "Mouse", "Rabbit", "Snake"]
        )
        self.assertEqual(hash_table.remove(22), "Snake")
        self.assertListEqual([k for k, _ in hash_table], [60, 20, 96, 71])
        self.assertListEqual(
            [v for _, v in hash_table], ["Dog", "Dolphin", "Mouse", "Rabbit"]
        )

        with self.assertRaises(RuntimeError):
            hash_table.remove(99)

        self.assertEqual(hash_table.remove(20), "Dolphin")
        self.assertEqual(hash_table.remove(71), "Rabbit")
        self.assertEqual(hash_table.remove(60), "Dog")
        self.assertEqual(hash_table.remove(96), "Mouse")

        with self.assertRaises(RuntimeError):
            hash_table.remove(80)


if __name__ == "__main__":
    unittest.main()

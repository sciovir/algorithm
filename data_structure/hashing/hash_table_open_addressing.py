"""
Hash Table Open Addressing
"""
import unittest
from typing import Generator, Any


class HashTable:
    def __init__(self, cap: int = 10):
        self._keys: list = [None] * cap
        self._values: list = [None] * cap
        self._cap = cap
        self._size = 0

    def __iter__(self) -> Generator[tuple[Any, Any], Any, None]:
        if not self.is_empty():
            for i in range(len(self._keys)):
                if self._keys[i]:
                    yield self._keys[i], self._values[i],

    def __repr__(self) -> str:
        return ", ".join([f"[{k}: {v}]" for k, v in self])

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._size == 0

    @property
    def keys(self) -> list[Any]:
        return [k for k, _ in self]

    def _hashing(self, key: Any) -> int:
        hash_key = int(key) % self._cap
        if hash_key < 0:
            hash_key += self._cap
        return hash_key

    def _rehashing(self) -> int:
        for i in range(self._cap):
            if self._keys[i] is None:
                return i
        raise RuntimeError("Hash table is full")

    def get(self, key: Any) -> Any:
        index = 0
        while index < self._cap:
            if self._keys[index] and self._keys[index] == key:
                break
            index += 1

        if index >= self._cap:
            raise RuntimeError("Key is not exist in this hash table")
        return self._values[index]

    def insert(self, key: Any, value: Any) -> None:
        for i in range(self._cap):
            if self._keys[i] and self._keys[i] == key:
                raise RuntimeError("Key is already exist")

        hash_key = self._hashing(key)
        if self._keys[hash_key]:
            hash_key = self._rehashing()

        self._keys[hash_key] = key
        self._values[hash_key] = value
        self._size += 1

    def remove(self, key: Any) -> Any:
        index = 0
        while index < self._cap:
            if self._keys[index] and self._keys[index] == key:
                break
            index += 1
        if index >= self._cap:
            raise RuntimeError("Key is not exist")

        removed = self._values[index]
        self._keys[index] = None
        self._values[index] = None

        self._size -= 1
        return removed


class TestHashTableOpenAddressing(unittest.TestCase):
    def test_integer_string_hash_table(self):
        hash_table: HashTable = HashTable()

        self.assertTrue(hash_table.is_empty())
        self.assertEqual(hash_table.size, 0)

        hash_table.insert(18, "Cat")
        hash_table.insert(60, "Dog")
        hash_table.insert(20, "Dolphin")
        hash_table.insert(96, "Mouse")
        hash_table.insert(71, "Rabbit")
        hash_table.insert(22, "Snake")

        self.assertFalse(hash_table.is_empty())
        self.assertListEqual([k for k, _ in hash_table], [60, 20, 71, 22, 96, 18])
        self.assertListEqual(
            [v for _, v in hash_table],
            ["Dog", "Dolphin", "Rabbit", "Snake", "Mouse", "Cat"],
        )

        self.assertEqual(hash_table.get(60), "Dog")
        self.assertEqual(hash_table.get(96), "Mouse")

        self.assertEqual(hash_table.remove(18), "Cat")
        self.assertListEqual([k for k, _ in hash_table], [60, 20, 71, 22, 96])
        self.assertListEqual(
            [v for _, v in hash_table], ["Dog", "Dolphin", "Rabbit", "Snake", "Mouse"]
        )
        self.assertEqual(hash_table.remove(22), "Snake")
        self.assertListEqual([k for k, _ in hash_table], [60, 20, 71, 96])
        self.assertListEqual(
            [v for _, v in hash_table], ["Dog", "Dolphin", "Rabbit", "Mouse"]
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

"""
Naive pattern searching algorithm
"""
import unittest


def naive_pattern_searching(text: str, pattern: str) -> list[int]:
    if len(text) < 2 or len(pattern) < 2 or len(text) < len(pattern):
        return []

    ret: list[int] = []
    for i in range(len(text) - len(pattern)):
        matched = True
        for j in range(len(pattern) - 1):
            if text[i + j] != pattern[j]:
                matched = False
                break

        if matched:
            ret.append(i)

    return ret


class TestNaivePatternSearching(unittest.TestCase):
    def test_handles_multiple_pattern_input(self):
        self.assertListEqual(
            naive_pattern_searching("AABAACAADAABAAABAA", "AABA"), [0, 9, 13]
        )
        self.assertListEqual(naive_pattern_searching("AAABSSSAAAOSI", "FHJK"), [])
        self.assertListEqual(naive_pattern_searching("AAACAAIOAAADAAIS", "AAACA"), [0])

    def test_handles_invalid_input(self):
        self.assertListEqual(naive_pattern_searching("", ""), [])
        self.assertListEqual(naive_pattern_searching("ABC", ""), [])
        self.assertListEqual(naive_pattern_searching("", "DEF"), [])
        self.assertListEqual(naive_pattern_searching("AA", "DEF"), [])


if __name__ == "__main__":
    unittest.main()

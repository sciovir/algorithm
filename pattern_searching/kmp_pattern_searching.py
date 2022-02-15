"""
KMP pattern searching algorithm
"""
import unittest


def kmp_pattern_searching(text: str, pattern: str) -> list[int]:
    if len(text) < 2 or len(pattern) < 2 or len(text) < len(pattern):
        return []

    lps: list[int] = [0] * len(pattern)
    i, j = 1, 0
    ret: list[int] = []

    lps[0] = 0
    while i < len(pattern) - 1:
        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
            i += 1
        elif j > 0:
            j = lps[j - 1]
        else:
            lps[i] = 0
            i += 1

    i = j = 0
    while i < len(text) - 1:
        if text[i] == pattern[j]:
            i += 1
            j += 1

        if j == len(pattern) - 1:
            ret.append(i - j)
            j = lps[j - 1]
        elif i < len(text) - 1 and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

    return ret


class TestKMPPatternSearching(unittest.TestCase):

    def test_handles_multiple_pattern_input(self):
        self.assertListEqual(kmp_pattern_searching('AABAACAADAABAAABAA', 'AABA'), [0, 9, 13])
        self.assertListEqual(kmp_pattern_searching('AAABSSSAAAOSI', 'FHJK'), [])
        self.assertListEqual(kmp_pattern_searching('AAACAAIOAAADAAIS', 'AAACA'), [0])

    def test_handles_invalid_input(self):
        self.assertListEqual(kmp_pattern_searching('', ''), [])
        self.assertListEqual(kmp_pattern_searching('ABC', ''), [])
        self.assertListEqual(kmp_pattern_searching('', 'DEF'), [])
        self.assertListEqual(kmp_pattern_searching('AA', 'DEF'), [])


if __name__ == '__main__':
    unittest.main()

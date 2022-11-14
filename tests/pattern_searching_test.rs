use algorithm::pattern_searching::*;

// KMP pattern searching
#[test]
fn kmp_pattern_searching_should_search_pattern_in_text_correctly() {
    let mut answer = vec![0, 9, 13];
    let mut result = kmp_pattern_searching::search("AABAACAADAABAAABAA", "AABA");
    assert_eq!(&answer[..], &result[..]);

    answer = vec![];
    result = kmp_pattern_searching::search("AAABSSSAAAOSI", "FHJK");
    assert_eq!(&answer[..], &result[..]);

    answer = vec![0];
    result = kmp_pattern_searching::search("AAACAAIOAAADAAIS", "AAACA");
    assert_eq!(&answer[..], &result[..]);
}

// Naive pattern searching
#[test]
fn naive_pattern_searching_should_search_pattern_in_text_correctly() {
    let mut answer = vec![0, 9, 13];
    let mut result = kmp_pattern_searching::search("AABAACAADAABAAABAA", "AABA");
    assert_eq!(&answer[..], &result[..]);

    answer = vec![];
    result = kmp_pattern_searching::search("AAABSSSAAAOSI", "FHJK");
    assert_eq!(&answer[..], &result[..]);

    answer = vec![0];
    result = kmp_pattern_searching::search("AAACAAIOAAADAAIS", "AAACA");
    assert_eq!(&answer[..], &result[..]);
}

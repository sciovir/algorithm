pub fn search(text: &str, pattern: &str) -> Vec<usize> {
    if text.len() < 2 || pattern.len() < 2 || text.len() < pattern.len() {
        return vec![];
    }

    let text_chars = text.as_bytes();
    let pattern_chars = pattern.as_bytes();

    let mut lps = vec![0; pattern.len()];
    let (mut i, mut j) = (1, 0);
    let mut ret = vec![];

    lps[0] = 0;
    while i < pattern.len() - 1 {
        if pattern_chars[i] == pattern_chars[j] {
            j += 1;
            lps[i] = j;
            i += 1;
        } else if j > 0 {
            j = lps[j - 1];
        } else {
            lps[i] = 0;
            i += 1;
        }
    }

    i = 0;
    j = 0;
    while i < text.len() - 1 {
        if text_chars[i] == pattern_chars[j] {
            i += 1;
            j += 1;
        }

        if j == pattern.len() - 1 {
            ret.push(i - j);
            j = lps[j - 1];
        } else if i < text.len() - 1 && pattern_chars[j] != text_chars[i] {
            if j != 0 {
                j = lps[j - 1];
            } else {
                i += 1;
            }
        }
    }

    ret
}

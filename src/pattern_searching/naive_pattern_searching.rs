pub fn search(text: &str, pattern: &str) -> Vec<usize> {
    if text.len() < 2 || pattern.len() < 2 || text.len() < pattern.len() {
        return vec![];
    }

    let text_chars = text.as_bytes();
    let pattern_chars = pattern.as_bytes();

    let mut ret = vec![];
    for i in 0..text.len() - pattern.len() {
        let mut matched = true;

        for j in 0..pattern.len() - 1 {
            if text_chars[i + j] != pattern_chars[j] {
                matched = false;
                break;
            }
        }

        if matched {
            ret.push(i);
        }
    }

    ret
}

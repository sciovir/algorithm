pub fn search<T: PartialOrd>(arr: &[T], key: T, lo: usize, hi: usize) -> Option<usize> {
    if lo > hi {
        return None;
    }

    let mi = (lo + hi) / 2;
    if arr[mi] == key {
        return Some(mi);
    } else if key < arr[mi] {
        if mi == 0 {
            return None;
        }

        return search(arr, key, lo, mi - 1);
    }

    search(arr, key, mi + 1, hi)
}

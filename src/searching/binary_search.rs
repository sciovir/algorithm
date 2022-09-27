pub fn search<T: PartialOrd>(sorted_array: &[T], key: T, lo: isize, hi: isize) -> isize {
    if lo > hi {
        return -1;
    }

    let mi = (lo + hi) / 2;
    if sorted_array[usize::try_from(mi).unwrap()] == key {
        return mi;
    } else if sorted_array[usize::try_from(mi).unwrap()] > key {
        return search(sorted_array, key, lo, mi - 1);
    }

    return search(sorted_array, key, mi + 1, hi);
}

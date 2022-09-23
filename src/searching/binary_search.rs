pub fn search<T: PartialOrd>(sorted_array: &[T], key: T, lo: usize, hi: usize) -> isize {
    if lo > hi {
        return -1;
    }

    let mi = (lo + hi) / 2;
    if sorted_array[mi] == key {
        return mi as isize;
    } else if sorted_array[mi] > key {
        return search(sorted_array, key, lo, mi - 1);
    }

    return search(sorted_array, key, mi + 1, hi);
}

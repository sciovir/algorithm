pub fn search<T: PartialOrd>(sorted_array: &[T], key: T) -> isize {
    for (i, v) in sorted_array.iter().enumerate() {
        if v == &key {
            return i as isize;
        }
    }
    -1
}

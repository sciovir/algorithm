pub fn search<T: PartialEq>(arr: &[T], key: T) -> Option<usize> {
    for i in 0..arr.len() {
        if arr[i] == key {
            return Some(i);
        }
    }

    None
}

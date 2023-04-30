pub fn sort<T: PartialOrd>(arr: &mut [T]) {
    for i in 0..arr.len() - 1 {
        for j in i + 1..arr.len() {
            if arr[i] > arr[j] {
                arr.swap(i, j);
            }
        }
    }
}

/// Bubble Sort works by repeatedly swapping the elements if they are in wrong order.
/// Examples:
/// - Giving an array [5, 2, 3, 1, 4], assuming that we sort the array by
/// ascending order.
/// - Starting with the first index, we compare the element at current index
/// with the rest. At the end of first loop, we get the smallest element at
/// current index. 0  1  2  3  4 -> array's indexes [5, 2, 3, 1, 4] we compare
/// the first 2 elements then swap 5 and 2 cause 5 > 2 i  j [2, 5, 3, 1, 4] since
/// these elements are in order (2 < 3), we don't swap them i     j [2, 5, 3, 1, 4]
/// swap 2 and 1 i        j [1, 5, 3, 2, 4] don't swap i           j
/// - Keep looping i to pre-last index and j from i + 1 to the last index.
/// - After all the loops, array is now sorted.
pub fn sort<T: PartialOrd>(array: &mut [T]) {
    for i in 0..array.len() - 1 {
        for j in i + 1..array.len() {
            if array[j] < array[i] {
                array.swap(i, j);
            }
        }
    }
}

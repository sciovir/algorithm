use algorithm::sorting::*;

#[test]
fn bubble_sort_should_sort_array_with_different_data_types_properly() {
    let mut array: [i32; 11] = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3];
    let result: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    bubble_sort::sort(&mut array);
    assert_eq!(&array[..], &result[..]);

    let mut array: [&str; 8] = ["c", "asm", "rust", "cpp", "python", "go", "swift", "sql"];
    let result: [&str; 8] = ["asm", "c", "cpp", "go", "python", "rust", "sql", "swift"];
    bubble_sort::sort(&mut array);
    assert_eq!(&array[..], &result[..]);

    let mut array: [f32; 8] = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9];
    let result: [f32; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];
    bubble_sort::sort(&mut array);
    assert_eq!(&array[..], &result[..]);
}

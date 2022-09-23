use algorithm::searching::*;

// Linear search
#[test]
fn linear_search_should_search_key_with_different_data_types_properly() {
    let array: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    assert_eq!(linear_search::search(&array, 8), 4);

    let array: [&str; 8] = ["asm", "c", "cpp", "go", "python", "rust", "sql", "swift"];
    assert_eq!(linear_search::search(&array, "c"), 1);

    let array: [f32; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];
    assert_eq!(linear_search::search(&array, 9.5), 7);
}

#[test]
fn linear_search_should_return_if_key_does_not_exist() {
    let array: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    assert_eq!(linear_search::search(&array, 1), -1);

    let array: [&str; 8] = ["asm", "c", "cpp", "go", "python", "rust", "sql", "swift"];
    assert_eq!(linear_search::search(&array, "java"), -1);

    let array: [f32; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];
    assert_eq!(linear_search::search(&array, 4.5), -1);
}

// Binary search
#[test]
fn binary_search_should_search_key_with_different_data_types_properly() {
    let array: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    assert_eq!(binary_search::search(&array, 8, 0, array.len() - 1), 4);

    let array: [&str; 8] = ["asm", "c", "cpp", "go", "python", "rust", "sql", "swift"];
    assert_eq!(binary_search::search(&array, "c", 0, array.len() - 1), 1);

    let array: [f32; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];
    assert_eq!(binary_search::search(&array, 9.5, 0, array.len() - 1), 7);
}

#[test]
fn binary_search_should_return_if_key_does_not_exist() {
    let array: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    assert_eq!(binary_search::search(&array, 1, 0, array.len() - 1), -1);

    let array: [&str; 8] = ["asm", "c", "cpp", "go", "python", "rust", "sql", "swift"];
    assert_eq!(
        binary_search::search(&array, "java", 0, array.len() - 1),
        -1
    );

    let array: [f32; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];
    assert_eq!(binary_search::search(&array, 4.5, 0, array.len() - 1), -1);
}

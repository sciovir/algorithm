use algorithm::searching::*;

const INTS: [i32; 11] = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
const STRS: [&str; 7] = ["c", "cpp", "go", "java", "python", "sql", "swift"];
const FLTS: [f64; 8] = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];

#[test]
fn test_linear_search_handles_multiple_types_of_array() {
    assert!(matches!(linear_search::search(&INTS, 8), Some(4)));
    assert!(matches!(linear_search::search(&STRS, "cpp"), Some(1)));
    assert!(matches!(linear_search::search(&FLTS, 9.5), Some(7)));
}

#[test]
fn test_linear_search_handles_non_exist_input() {
    assert!(matches!(linear_search::search(&INTS, 1), None));
    assert!(matches!(linear_search::search(&STRS, "rust"), None));
    assert!(matches!(linear_search::search(&FLTS, 4.5), None));
}

#[test]
fn test_binary_search_handles_multiple_types_of_array() {
    assert!(matches!(
        binary_search::search(&INTS, 8, 0, INTS.len() - 1),
        Some(4)
    ));
    assert!(matches!(
        binary_search::search(&STRS, "cpp", 0, STRS.len() - 1),
        Some(1)
    ));
    assert!(matches!(
        binary_search::search(&FLTS, 9.5, 0, FLTS.len() - 1),
        Some(7)
    ));
}

#[test]
fn test_binary_search_handles_non_exist_input() {
    assert!(matches!(
        binary_search::search(&INTS, 1, 0, INTS.len() - 1),
        None
    ));
    assert!(matches!(
        binary_search::search(&STRS, "rust", 0, STRS.len() - 1),
        None
    ));
    assert!(matches!(
        binary_search::search(&FLTS, 4.5, 0, FLTS.len() - 1),
        None
    ));
}

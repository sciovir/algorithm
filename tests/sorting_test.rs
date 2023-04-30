use algorithm::sorting::*;

#[test]
fn test_bubble_sort_handles_multiple_types_of_array() {
    let mut ints = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3];
    let mut strs = ["c", "java", "cpp", "python", "go", "sql", "swift"];
    let mut flts = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9];

    let sorted_ints = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40];
    let sorted_strs = ["c", "cpp", "go", "java", "python", "sql", "swift"];
    let sorted_flts = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5];

    bubble_sort::sort(&mut ints);
    assert_eq!(ints, sorted_ints);

    bubble_sort::sort(&mut strs);
    assert_eq!(strs, sorted_strs);

    bubble_sort::sort(&mut flts);
    assert_eq!(flts, sorted_flts);
}

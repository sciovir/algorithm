use algorithm::divide_conquer::*;

// Maximum subarray
#[test]
fn random_integer_array_maximum_subarray_should_be_found() {
    let array = [
        12, -2, -23, 18, -1, -14, -21, 16, 19, -5, 10, -3, -20, 13, -4, -7,
    ];

    let result = maximum_subarray::find(&array, 0, array.len() - 1);
    println!("{:?}", result);
    assert_eq!(result.0, 7);
    assert_eq!(result.1, 10);
    assert_eq!(result.2, 40);
}

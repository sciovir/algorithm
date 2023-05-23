use ::algorithm::math::*;

#[test]
fn test_fibonacci_handles_zero_input() {
    assert_eq!(fibonacci::binary_calc(0), 0);
    assert_eq!(fibonacci::linear_calc(0).0, 0);
}

#[test]
fn test_fibonacci_handles_positive_input() {
    assert_eq!(fibonacci::binary_calc(1), 1);
    assert_eq!(fibonacci::binary_calc(2), 1);
    assert_eq!(fibonacci::binary_calc(3), 2);
    assert_eq!(fibonacci::binary_calc(6), 8);

    assert_eq!(fibonacci::linear_calc(1).0, 1);
    assert_eq!(fibonacci::linear_calc(2).0, 1);
    assert_eq!(fibonacci::linear_calc(3).0, 2);
    assert_eq!(fibonacci::linear_calc(6).0, 8);
}

#[test]
fn test_factorial_handles_zero_input() {
    assert_eq!(factorial::calc(0), 1);
}

#[test]
fn test_factorial_handles_positive_input() {
    assert_eq!(factorial::calc(1), 1);
    assert_eq!(factorial::calc(2), 2);
    assert_eq!(factorial::calc(3), 6);
    assert_eq!(factorial::calc(6), 720);
    assert_eq!(factorial::calc(8), 40320);
}

#[test]
fn test_catalan_handles_zero_input() {
    assert_eq!(catalan::calc(0), 1);
}

#[test]
fn test_catalan_handles_positive_input() {
    assert_eq!(catalan::calc(1), 1);
    assert_eq!(catalan::calc(2), 2);
    assert_eq!(catalan::calc(3), 5);
    assert_eq!(catalan::calc(4), 14);
    assert_eq!(catalan::calc(5), 42);
    assert_eq!(catalan::calc(9), 4862);
}
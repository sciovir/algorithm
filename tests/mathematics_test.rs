use algorithm::mathematics::*;

// Fibonacci
#[test]
fn fibonacci_should_calculate_nth_number_correctly() {
    assert_eq!(fibonacci::calculate(1).0, 1);
    assert_eq!(fibonacci::calculate(2).0, 1);
    assert_eq!(fibonacci::calculate(3).0, 2);
    assert_eq!(fibonacci::calculate(6).0, 8);
}

// Factorial
#[test]
fn factorial_should_calculate_nth_number_correctly() {
    assert_eq!(factorial::calculate(1), 1);
    assert_eq!(factorial::calculate(2), 2);
    assert_eq!(factorial::calculate(3), 6);
    assert_eq!(factorial::calculate(6), 720);
    assert_eq!(factorial::calculate(8), 40320);
}

// Catalan
#[test]
fn catalan_should_calculate_nth_number_correctly() {
    assert_eq!(catalan::calculate(2), 2);
    assert_eq!(catalan::calculate(3), 5);
    assert_eq!(catalan::calculate(4), 14);
    assert_eq!(catalan::calculate(8), 1430);
    assert_eq!(catalan::calculate(9), 4862);
}

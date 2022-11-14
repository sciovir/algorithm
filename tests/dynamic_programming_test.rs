use algorithm::dynamic_programming::*;

// Catalan
#[test]
fn catalan_should_calculate_nth_number_correctly() {
    assert_eq!(catalan::calculate(2), 2);
    assert_eq!(catalan::calculate(3), 5);
    assert_eq!(catalan::calculate(4), 14);
    assert_eq!(catalan::calculate(8), 1430);
    assert_eq!(catalan::calculate(9), 4862);
}

// Fibonacci
#[test]
fn fibonacci_should_calculate_nth_number_correctly() {
    assert_eq!(fibonacci::calculate(2), 1);
    assert_eq!(fibonacci::calculate(3), 2);
    assert_eq!(fibonacci::calculate(4), 3);
    assert_eq!(fibonacci::calculate(8), 21);
    assert_eq!(fibonacci::calculate(9), 34);
}

// Ugly number
#[test]
fn ugly_number_should_calculate_nth_number_correctly() {
    assert_eq!(ugly_number::calculate(2), 2);
    assert_eq!(ugly_number::calculate(3), 3);
    assert_eq!(ugly_number::calculate(4), 4);
    assert_eq!(ugly_number::calculate(8), 9);
    assert_eq!(ugly_number::calculate(9), 10);
}

// Zero one knapsack
#[test]
fn zero_one_knapsack_should_calculate_max_value_correctly() {
    assert_eq!(
        zero_one_knapsack::calculate(&mut vec![(1, 1), (4, 5), (3, 4), (5, 7)], 7),
        9
    );
    assert_eq!(
        zero_one_knapsack::calculate(&mut vec![(10, 60), (20, 100), (30, 120)], 50),
        220
    );
}

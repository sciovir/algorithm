use algorithm::greedy::*;

// Fractional knapsack
#[test]
fn fractional_knapsack_should_calculate_max_value_correctly() {
    let mut items = vec![(10, 60), (20, 100), (30, 120)];
    assert_eq!(fractional_knapsack::calculate(&mut items, 50), 240);
    assert_eq!(fractional_knapsack::calculate(&mut items, 60), 280);
    assert_eq!(fractional_knapsack::calculate(&mut items, 30), 160);
    assert_eq!(fractional_knapsack::calculate(&mut items, 5), 30);
}

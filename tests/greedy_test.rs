use algorithm::greedy::*;

#[test]
fn test_fractional_knapsack_handles_multiple_input() {
    let items = vec![(10, 60), (30, 120), (20, 100)];

    assert_eq!(fractional_knapsack::solve(&items, 50), 240);
    assert_eq!(fractional_knapsack::solve(&items, 60), 280);
    assert_eq!(fractional_knapsack::solve(&items, 30), 160);
    assert_eq!(fractional_knapsack::solve(&items, 5), 30);
}
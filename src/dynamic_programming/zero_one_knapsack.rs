use std::cmp::max;

pub fn calculate(items: &mut Vec<(u32, u32)>, target_weight: u32) -> u32 {
    items.sort_by_key(|item| item.0);
    let mut matrix: Vec<Vec<u32>> = vec![vec![0; target_weight as usize + 1]; items.len()];

    for r in 0..items.len() {
        for c in 1..target_weight as usize + 1 {
            if r == 0 {
                matrix[r][c] = items[r].1;
                continue;
            }
            if c < items[r].0 as usize {
                matrix[r][c] = matrix[r - 1][c];
            } else {
                matrix[r][c] = max(
                    items[r].1 + matrix[r - 1][c - items[r].0 as usize],
                    matrix[r - 1][c],
                )
            }
        }
    }

    matrix[items.len() - 1][target_weight as usize]
}

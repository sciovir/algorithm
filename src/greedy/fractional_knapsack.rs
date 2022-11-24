use std::cmp::Reverse;

pub fn calculate(items: &mut Vec<(u32, u32)>, target_weight: u32) -> u32 {
    items.sort_by_key(|item| Reverse(item.1 / item.0));
    let mut max_value = 0;
    let mut weight = target_weight;

    for item in items {
        if weight <= 0 {
            break;
        }

        if weight < item.0 {
            max_value += weight * item.1 / item.0;
            weight = 0;
        } else {
            max_value += item.1;
            weight -= item.0;
        }
    }

    max_value
}

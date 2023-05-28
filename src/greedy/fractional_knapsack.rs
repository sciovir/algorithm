pub fn solve(items: &Vec<(i32, i32)>, weight: i32) -> i32 {
    let mut arr = items.clone();
    let mut w = weight;
    arr.sort_by(|a, b| ((*a).1 / (*a).0).cmp(&((*b).1 / (*b).0)).reverse());

    let mut max_val = 0;
    for item in arr {
        if w - item.0 >= 0 {
            w -= item.0;
            max_val += item.1;
        } else {
            let fraction = w as f32 / item.0 as f32;
            max_val += (item.1 as f32 * fraction) as i32;
            break;
        }
    }

    max_val
}
pub fn find(array: &[i32], lo: usize, hi: usize) -> (usize, usize, i32) {
    if lo >= hi {
        return (lo, hi, array[lo]);
    }

    let mi: usize = (lo + hi) / 2;

    let left_tup = find(array, lo, mi);
    let right_tup = find(array, mi + 1, hi);
    let crossing_tup = find_crossing(array, lo, mi, hi);

    if left_tup.2 > right_tup.2 && left_tup.2 > crossing_tup.2 {
        return left_tup;
    } else if right_tup.2 > left_tup.2 && right_tup.2 > crossing_tup.2 {
        return right_tup;
    }

    crossing_tup
}

fn find_crossing(array: &[i32], lo: usize, mi: usize, hi: usize) -> (usize, usize, i32) {
    let mut left_sum = i32::MIN;
    let mut right_sum = i32::MIN;

    let mut sum: i32 = 0;
    let mut left_max = mi;
    let mut right_max = mi + 1;

    for i in (lo.wrapping_sub(1)..=mi).rev() {
        sum += array[i];
        if sum > left_sum {
            left_sum = sum;
            left_max = i;
        }
    }
    if left_max == mi {
        left_sum = array[mi];
    }

    sum = 0;
    for i in mi + 1..hi + 1 {
        sum += array[i];
        if sum > right_sum {
            right_sum = sum;
            right_max = i;
        }
    }

    sum = left_sum + right_sum;
    if left_sum > sum && left_sum > right_sum {
        return (left_max, mi, left_sum);
    } else if right_sum > left_sum && right_sum > sum {
        return (mi + 1, right_max, right_sum);
    }

    (left_max, right_max, sum)
}

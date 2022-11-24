use std::cmp::min;

pub fn calculate(n: u32) -> u32 {
    let mut ugly_number = vec![0; n as usize];

    let (mut i2, mut i3, mut i5) = (0, 0, 0);
    let (mut mul_2, mut mul_3, mut mul_5) = (2, 3, 5);

    let mut next_ugly_number = 1;
    ugly_number[0] = next_ugly_number;

    for i in 1..n as usize {
        next_ugly_number = min(mul_2, min(mul_3, mul_5));
        ugly_number[i] = next_ugly_number;

        if mul_2 == next_ugly_number {
            i2 += 1;
            mul_2 = ugly_number[i2] * 2;
        }
        if mul_3 == next_ugly_number {
            i3 += 1;
            mul_3 = ugly_number[i3] * 3;
        }
        if mul_5 == next_ugly_number {
            i5 += 1;
            mul_5 = ugly_number[i5] * 5;
        }
    }

    next_ugly_number
}

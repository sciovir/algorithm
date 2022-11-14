pub fn calculate(n: u32) -> u32 {
    if n < 2 {
        return 1;
    }

    let mut sum = 0;
    for i in 0..n {
        sum += calculate(i) * calculate(n - i - 1);
    }

    sum
}

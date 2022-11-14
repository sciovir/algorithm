pub fn calculate(n: u32) -> u32 {
    if n < 1 {
        1
    } else {
        n * calculate(n - 1)
    }
}

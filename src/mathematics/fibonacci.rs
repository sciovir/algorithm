pub fn calculate(n: u32) -> (u32, u32) {
    if n < 2 {
        return (n, 0);
    }

    let (x, y) = calculate(n - 1);
    (x + y, x)
}

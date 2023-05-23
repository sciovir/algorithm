pub fn calc(n: u32) -> u32 {
    if n == 0 {
        return 1;
    }

    n * calc(n - 1)
}
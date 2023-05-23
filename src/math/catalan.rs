pub fn calc(n: u32) -> u32 {
    if n <= 1 {
        return 1;
    }

    let mut ret = 0;
    for i in 0..n {
        ret += calc(i) *calc(n - i - 1);
    }

    ret
}
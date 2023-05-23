pub fn binary_calc(n: u32) -> u32 {
    if n <= 1 {
        return n;
    }

    binary_calc(n - 1) + binary_calc(n - 2)
}

pub fn linear_calc(n: u32) -> (u32, u32) {
    if n <= 1 {
        return (n, 0);
    }

    let ret = linear_calc(n - 1);
    (ret.0 + ret.1, ret.0)
}

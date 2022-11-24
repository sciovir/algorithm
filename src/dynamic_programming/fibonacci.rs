pub fn calculate(n: u32) -> u32 {
    let mut fibonacci = vec![0; n as usize + 1];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for i in 2..n as usize + 1 {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    fibonacci[n as usize]
}

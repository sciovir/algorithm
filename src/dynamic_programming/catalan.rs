pub fn calculate(n: u32) -> u32 {
    let mut catalan = vec![0; n as usize + 1];
    catalan[0] = 1;
    catalan[1] = 1;

    for i in 2..n as usize + 1 {
        for j in 0..i {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    catalan[n as usize]
}

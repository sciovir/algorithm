use algorithm::backtracking::*;

// Knight tour problem
#[test]
fn knight_start_from_top_left_should_be_solved_correctly() {
    let answer: [[i32; 8]; 8] = [
        [0, 33, 42, 63, 12, 25, 8, 21],
        [41, 62, 45, 32, 43, 22, 11, 24],
        [46, 1, 34, 13, 26, 9, 20, 7],
        [61, 40, 51, 44, 31, 18, 23, 10],
        [52, 47, 2, 35, 14, 27, 6, 19],
        [39, 60, 37, 50, 55, 30, 17, 28],
        [48, 53, 58, 3, 36, 15, 56, 5],
        [59, 38, 49, 54, 57, 4, 29, 16],
    ];

    let result = knight_tour::solve(0, 0);
    assert_eq!(result.is_some(), true);
    if let Some(arr) = result {
        assert_eq!(arr.len(), answer.len());
        for i in 0..arr.len() {
            assert_eq!(arr[i].len(), answer[i].len());
            for j in 0..arr[i].len() {
                assert_eq!(arr[i][j], answer[i][j]);
            }
        }
    }
}

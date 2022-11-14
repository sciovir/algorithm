const BOARD_SIZE: usize = 8;

pub fn solve(x: usize, y: usize) -> Option<[[i32; BOARD_SIZE]; BOARD_SIZE]> {
    let mut board = [[-1; BOARD_SIZE]; BOARD_SIZE];
    let x_mv = [2, 1, -1, -2, -2, -1, 2, 1];
    let y_mv = [1, 2, 2, 1, -1, -2, -1, -2];

    board[0][0] = 0;
    if solve_recursive(&mut board, x_mv, y_mv, 1, x, y) {
        return Some(board);
    }

    None
}

fn solve_recursive(
    board: &mut [[i32; BOARD_SIZE]; BOARD_SIZE],
    x_mv: [i32; BOARD_SIZE],
    y_mv: [i32; BOARD_SIZE],
    mv: usize,
    x: usize,
    y: usize,
) -> bool {
    if mv == BOARD_SIZE * BOARD_SIZE {
        return true;
    }

    for i in 0..BOARD_SIZE {
        let x_nxt: i32 = x as i32 + x_mv[i];
        let y_nxt: i32 = y as i32 + y_mv[i];

        if possible_move(&board, x_nxt, y_nxt) {
            let x_nxt: usize = x_nxt.try_into().unwrap();
            let y_nxt: usize = y_nxt.try_into().unwrap();

            board[x_nxt][y_nxt] = mv as i32;
            if solve_recursive(board, x_mv, y_mv, mv + 1, x_nxt, y_nxt) {
                return true;
            }

            board[x_nxt][y_nxt] = -1;
        }
    }

    false
}

fn possible_move(board: &[[i32; BOARD_SIZE]; BOARD_SIZE], x: i32, y: i32) -> bool {
    x >= 0
        && x < BOARD_SIZE.try_into().unwrap()
        && y >= 0
        && y < BOARD_SIZE.try_into().unwrap()
        && board[x as usize][y as usize] == -1
}

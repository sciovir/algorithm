use algorithm::backtracking::*;

// Knight tour problem
#[test]
fn knight_start_from_top_left_should_be_solved_correctly() {
    let result = knight_tour::solve(0, 0);
    match result {
        Some(x) => {
            for i in 0..x.len() {
                println!("{:?}", x[i]);
            }
        },
        None => println!("No solution found!"),
    }
}

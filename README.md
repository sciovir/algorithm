# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using Rust. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `rustc` and `cargo` are installed.

You might want to check out `[rustup](https://www.rust-lang.org/tools/install)`.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone git@github.com:khoaji/algorithm.git
$ cd algorithm
```

## Build and test
Using Cargo to build:
```shell script
$ cargo build
```

To run all test simply run `cargo test`. If you want to run specific test just add desired function name after command.

You can also run specific group of tests using `cargo test --test [test_file_name]`.

In able to debug you might want to see printed values, we can enable that using this option:
```shell script
$ cargo test -- --show-output
```

## Algorithms explanation
TBA

## References
[Rust Book](https://doc.rust-lang.org/book/) \
[Rust Testing](https://doc.rust-lang.org/rust-by-example/testing.html)

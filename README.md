# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using Rust. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `rust 2021 edition` or above is installed.
You might need to use `cargo` - the Rust package manager, it's already shipped when installing Rust or you can test each algorithm manually.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone git@github.com:khoarx/algorithm.git
$ cd algorithm
```

## Build and test
Install all dependencies and build crate:
```shell script
$ cargo build
```
Test your desired module by `cargo`:
```shell script
$ cargo test --test [module_name]
```
or run all tests:
```shell script
$ cargo test
```
For logging, use `cargo test -- --nocapture`

For example:
```shell script
$ cargo test --test sorting_test
```

## Algorithms explanation
TBA

## References
[Rust Book](https://doc.rust-lang.org/book) \
[Rust Testing](https://doc.rust-lang.org/rust-by-example/testing/unit_testing.html)

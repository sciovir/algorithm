# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using C. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `clang` or `gcc`, and `make` are installed.

GNU make is optional, it helps you build and run project easier, but you could manual run each file separately.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone git@github.com:khoadotc/algorithm.git
$ cd algorithm
```

## Build and run C
Using GNU make:
1. Create _bin_ directory at project root:
```shell script
$ mkdir bin
```
2. Build project with `make`, remember we are currently in project root (where `Makefile` is located):
```shell script
$ make
```
or you can clean all the old binaries by `make clean`
3. All binary files are located inside _bin/_ directory.

Using `clang` or `gcc` compiler:
1. Compile your desired file by compiler:
```shell script
$ gcc -std=c17 [path_to_source_file] -o [path_to_output_file]
```
or
```shell script
$ clang -std=c17 [path_to_source_file] -o [path_to_output_file]
```
2. Then run compiled binary file:
```shell script
$ ./[path_to_binary_file]
```
For example:
```shell script
$ gcc -std=c17 sorting/merge_sort.c -o bin/merge_sort
$ ./bin/merge_sort
```

## Algorithms explanation
TBA

## References
[C standards](https://www.iso-9899.info/wiki/The_Standard) \
[GNU make](gnu.org/software/make/manual/make.html)

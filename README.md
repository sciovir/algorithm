# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using C++. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `clang` or `gcc`, `make` (or `MSBuild` on Windows) and `cmake` are installed.

CMake is optional, it helps you build and run project easier, but you could manual run each file separately.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone git@github.com:larrng/algorithm.git
$ cd algorithm
```

## Build and run C++
Using CMake:
1. Create __build__ directory at project root:
```shell script
$ mkdir build
$ cd build
```
2. Build project with `cmake` and `make`, remember we are currently in __build__ folder:
```shell script
$ cmake ..
$ make
```
If you are on Windows use `MSBuild` instead of `make`:
```powershell
cmake ..
MSBuild.exe .\algorithm.sln
```
3. All binary files are located inside __build/bin/__ directory.

Using `clang` or `gcc` compiler:
1. Compile your desired file by compiler:
```shell script
$ clang++ -std=c++14 {path_to_source_file} -o {path_to_output_file}
```
or
```shell script
$ g++ -std=c++14 {path_to_source_file} -o {path_to_output_file}
```
2. Then run compiled binary file:
```shell script
$ ./{path_to_binary_file}
```
For example:
```shell script
$ clang++ -std=c++14 sorting/merge_sort.cc -o build/bin/merge_sort
$ ./build/bin/merge_sort
```

Add `-DCMAKE_BUILD_TYPE=Debug` or `-DCMAKE_BUILD_TYPE=Release` argument to `cmake` command for `Debug`, `Release` respectively.

## Algorithms explanation
TBA

## References
[C++ Documentation](https://isocpp.org/) \
[CMake](https://cmake.org/documentation/) \
[GoogleTest](https://google.github.io/googletest/)

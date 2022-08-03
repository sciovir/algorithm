# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using Python. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `python3.10` or above is installed.
You might need to install`poetry` and `poethepoet`, it will save your time.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone git@github.com:khoarx/algorithm.git
$ cd algorithm
```

## Build and test
Install all dependencies:
```shell script
$ poetry install
```
Execute your desired unittest by `python` command
```shell script
$ python [file_name].py
```
or run all unittests in a directory
```shell script
$ python -m unittest discover -s [directory_name] -p '*.py'
```
Alternatively, use `poe`
```shell script
$ poe test -D [directory_name]
```

For example:
```shell script
$ python divide_conquer/maximum_subarray.py
$ python -m unittest discover -s sorting -p '*.py'
```
with `poe`:
```shell script
$ poe test -D sorting
```

## Algorithms explanation
TBA

## References
[Python Documentation](https://www.python.org/doc/) \
[Python Unittest](https://docs.python.org/3/library/unittest.html) \
[Poetry](https://python-poetry.org/)

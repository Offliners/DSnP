# Data Structure and Programming
This repository is where I practice implementing data structures using C or C++, and use Python3 to generate testcases to compare and analyze each data structure's usage of time and memory.

## Usage
```shell
# Change directory to the data structure you are interested in
$ cd ./{data_struct_dir}/{data_struct_series_dir}

# (Optional) If you want to re-generate new testcases, you can change the random seed in config.py, then run testcase_gen.py
$ python3 testcase_gen.py

# Compare the output generated by C or C++ with the golden output generated by Python3
# and check whether the output generated by C or C++ can pass all testcases
$ python3 compare.py
```
## Outline
### Linked List series
* Linked List
    * Implement in C++
    * Implement in C

### Stack series
* Stack
    * Implement with STL in C++
    * Implement with array in C
    * Implement with linked list in C
* Min Stack
    * Implement with STL in C++
    * Implement with array in C

### Queue series
* Queue
    * Implement with STL in C++
    * Implement with array in C
    * Implement with linked list in C

### Tree

### Hash

### Sort
* Sort
    * Implement with algorithm in C++
    * Implement with qsort in C
* Bubble Sort
    * Implement in C++
    * Implement in C
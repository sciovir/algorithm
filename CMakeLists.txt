cmake_minimum_required(VERSION 3.25)
project(algorithm CXX)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_BUILD_TYPE Debug)

include_directories("${CMAKE_SOURCE_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

add_executable(singly_linked_list data_structure/linked_list/singly_linked_list.cc)
add_executable(doubly_linked_list data_structure/linked_list/doubly_linked_list.cc)
add_executable(circularly_linked_list data_structure/linked_list/circularly_linked_list.cc)

add_executable(stack data_structure/stack/stack.cc)

add_executable(queue data_structure/queue/queue.cc)
add_executable(max_priority_queue data_structure/queue/max_priority_queue.cc)
add_executable(min_priority_queue data_structure/queue/min_priority_queue.cc)

add_executable(max_heap data_structure/heap/max_heap.cc)
add_executable(min_heap data_structure/heap/min_heap.cc)

add_executable(binary_tree data_structure/tree/binary_tree.cc)
add_executable(binary_search_tree data_structure/tree/binary_search_tree.cc)

add_executable(hash_table_separate_chaining data_structure/hashing/hash_table_separate_chaining.cc)
add_executable(hash_table_open_addressing data_structure/hashing/hash_table_open_addressing.cc)

add_executable(adjacency_list_graph data_structure/graph/adjacency_list_graph.cc)

add_executable(insertion_sort sorting/insertion_sort.cc)
add_executable(bubble_sort sorting/bubble_sort.cc)
add_executable(merge_sort sorting/merge_sort.cc)
add_executable(heap_sort sorting/heap_sort.cc)
add_executable(quick_sort sorting/quick_sort.cc)
add_executable(counting_sort sorting/counting_sort.cc)
add_executable(radix_sort sorting/radix_sort.cc)
add_executable(bucket_sort sorting/bucket_sort.cc)

# Linear search
add_executable(linear_search searching/linear_search.cc)
# Binary search
add_executable(binary_search searching/binary_search.cc)

# Factorial
add_executable(factorial mathematics/factorial.cc )
# Fibonacci
add_executable(fibonacci mathematics/fibonacci.cc)
# Catalan
add_executable(catalan mathematics/catalan.cc)

# Maximum Subarray
add_executable(maximum_subarray divide_conquer/maximum_subarray.cc)

# Knight tour
add_library(knight_tour backtracking/knight_tour.cc)
add_executable(
  knight_tour_test
  backtracking/knight_tour_test.cc
)
target_link_libraries(
  knight_tour_test
  knight_tour
  gtest_main
)
gtest_discover_tests(knight_tour_test)
# Rat in maze
add_library(rat_in_maze backtracking/rat_in_maze.cc)
add_executable(
  rat_in_maze_test
  backtracking/rat_in_maze_test.cc
)
target_link_libraries(
  rat_in_maze_test
  rat_in_maze
  gtest_main
)
gtest_discover_tests(rat_in_maze_test)
# N queen
add_library(n_queen backtracking/n_queen.cc)
add_executable(
  n_queen_test
  backtracking/n_queen_test.cc
)
target_link_libraries(
  n_queen_test
  n_queen
  gtest_main
)
gtest_discover_tests(n_queen_test)

# Ugly number
add_executable(ugly_number dynamic_programming/ugly_number.cc)
# Fibonacci dynamic programming
add_executable(fibonacci_dp dynamic_programming/fibonacci_dp.cc)
# Catalan dynamic programming
add_executable(catalan_dp dynamic_programming/catalan_dp.cc)
# Zero-One knapsack
add_executable(zero_one_knapsack dynamic_programming/zero_one_knapsack.cc)

# Naive pattern searching
add_executable(naive_pattern_searching pattern_searching/naive_pattern_searching.cc)
# KMP pattern searching
add_executable(kmp_pattern_searching pattern_searching/kmp_pattern_searching.cc)

# Fractional knapsack
add_executable(fractional_knapsack greedy/fractional_knapsack.cc )

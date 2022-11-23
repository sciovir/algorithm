#include "sorting_util.h"
#include <stdio.h>

/**
 * Bubble Sort works by repeatedly swapping the elements if they are in wrong
 * order.
 * @tparam T array's class
 * @tparam N size of array
 * @param array unsorted array
 *
 * Examples:
 *  - Giving an array [5, 2, 3, 1, 4], assuming that we sort the array by
 * ascending order.
 *  - Starting with the first index, we compare the element at current index
 * with the rest. At the end of first loop, we get the smallest element at
 * current index. 0  1  2  3  4 -> array's indexes [5, 2, 3, 1, 4] we compare
 * the first 2 elements then swap 5 and 2 cause 5 > 2 i  j [2, 5, 3, 1, 4] since
 * these elements are in order (2 < 3), we don't swap them i     j [2, 5, 3, 1,
 * 4] swap 2 and 1 i        j [1, 5, 3, 2, 4] don't swap i           j
 *  - Keep looping i to pre-last index and j from i + 1 to the last index.
 *  - After all the loops, array is now sorted.
 */
void bubble_sort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        swap_int(&array[i], &array[j]);
      }
    }
  }
}

void test() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  bubble_sort(integers, ARRSZ(integers));
  assert_array_int(integers, ARRSZ(integers),
                   (int[]){2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40}, 11);
}

int main(int argc, const char *argv[]) {
  printf("Running test for bubble sort\n");
  test();
  return 0;
}

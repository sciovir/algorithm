#include <assert.h>
#include <stdio.h>

#define ARRSZ(a) (sizeof(a) / sizeof((a)[0]))

int binary_search(int array[], int key, int lo, int hi) {
  if (lo > hi) {
    return -1;
  }

  int mi = (lo + hi) / 2;
  if (array[mi] == key) {
    return mi;
  } else if (key < array[mi]) {
    return binary_search(array, key, lo, mi - 1);
  } else {
    return binary_search(array, key, mi + 1, hi);
  }
}

void test() {
  int array[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};

  assert(binary_search(array, 8, 0, ARRSZ(array) - 1) == 4);
  assert(binary_search(array, 5, 0, ARRSZ(array) - 1) == 2);
  assert(binary_search(array, 32, 0, ARRSZ(array) - 1) == 9);

  assert(binary_search(array, 1, 0, ARRSZ(array) - 1) == -1);
  assert(binary_search(array, 100, 0, ARRSZ(array) - 1) == -1);

  printf("PASSED\n");
}

int main(int argc, const char *argv[]) {
  printf("Testing binary search implementation...\n");
  test();
  return 0;
}

#include <assert.h>
#include <stdio.h>

#define ARRSZ(a) (sizeof(a) / sizeof((a)[0]))

int linear_search(int array[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (array[i] == key) {
      return i;
    }
  }

  return -1;
}

void test() {
  int array[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};

  assert(linear_search(array, ARRSZ(array), 8) == 4);
  assert(linear_search(array, ARRSZ(array), 5) == 2);
  assert(linear_search(array, ARRSZ(array), 32) == 9);

  assert(linear_search(array, ARRSZ(array), 1) == -1);
  assert(linear_search(array, ARRSZ(array), 100) == -1);

  printf("PASSED\n");
}

int main(int argc, const char *argv[]) {
  printf("Testing linear search implementation...\n");
  test();
  return 0;
}

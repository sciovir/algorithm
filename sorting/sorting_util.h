#pragma once
#include <assert.h>
#include <stdio.h>

#define ARRSZ(a) (sizeof(a) / sizeof((a)[0]))

static inline void swap_int(int *x, int *y) {
  int z = *x;
  *x = *y;
  *y = z;
}

static inline void assert_array_int(int farr[], int fsz, int sarr[], int ssz) {
  assert(fsz == ssz);
  for (int i = 0; i < fsz; i++) {
    assert(farr[i] == sarr[i]);
  }
  printf("PASS\n");
}

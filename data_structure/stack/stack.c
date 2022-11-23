#include "stack.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Stack implementation
 */
cstack_t *create_stack(int cap) {
  cstack_t *stack = (cstack_t *)malloc(sizeof(cstack_t));
  stack->data = malloc(sizeof(void *) * cap);
  stack->cap = cap;
  stack->top = -1;
  return stack;
}

void delete_stack(cstack_t *stack) {
  free(stack->data);
  free(stack);
}

void print_stack(cstack_t *stack) {
  for (int i = 0; i <= stack->top; i++) {
    printf("%p ", stack->data[i]);
  }
}

int size(cstack_t *stack) { return stack->top + 1; }

bool is_empty(cstack_t *stack) { return stack->top < 0; }

bool is_full(cstack_t *stack) { return size(stack) == stack->cap; }

bool push(cstack_t *stack, void *data) {
  if (is_full(stack)) {
    return false;
  }

  stack->data[++stack->top] = data;
  return true;
}

void *pop(cstack_t *stack) {
  if (is_empty(stack)) {
    return NULL;
  }

  return stack->data[stack->top--];
}

const void *top(cstack_t *stack) {
  if (is_empty(stack)) {
    return NULL;
  }

  return stack->data[stack->top];
}

// Testing
void test() {
  cstack_t *stack = create_stack(20);
  assert(is_empty(stack));
  assert(size(stack) == 0);

  push(stack, (void *)8);
  push(stack, (void *)6);
  push(stack, (void *)26);
  push(stack, (void *)9);
  push(stack, (void *)7);
  push(stack, (void *)22);

  assert(!is_empty(stack));
  assert(size(stack) == 6);

  assert((int)top(stack) == 22);
  assert((int)pop(stack) == 22);
  assert(size(stack) == 5);

  assert((int)pop(stack) == 7);
  assert((int)top(stack) == 9);
  assert(size(stack) == 4);

  delete_stack(stack);
  printf("PASSED\n");
}

int main(int argc, const char *argv[]) {
  printf("Testing stack implementation...\n");
  test();
  return 0;
}

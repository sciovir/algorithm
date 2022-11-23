#pragma once
#include <stdbool.h>
#include <stdio.h>

/**
 * Stack ...
 */
typedef struct Stack {
  void **data;
  int cap;
  int top;
} cstack_t;

cstack_t *create_stack(int cap);
void delete_stack(cstack_t *stack);
void print_stack(cstack_t *stack);
int size(cstack_t *stack);
bool is_empty(cstack_t *stack);
bool is_full(cstack_t *stack);
bool push(cstack_t *stack, void *data);
void *pop(cstack_t *stack);
const void *top(cstack_t *stack);

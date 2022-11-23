#include "singly_linked_list.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Singly linked list implementation
 */
node_t *create_node(void *data) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  return node;
}

singly_linked_list_t *create_list() {
  singly_linked_list_t *list =
      (singly_linked_list_t *)malloc(sizeof(singly_linked_list_t));
  list->head = NULL;
  list->size = 0;
  return list;
}

void delete_list(singly_linked_list_t *list) {
  node_t *tmp = list->head;
  if (!tmp) {
    return;
  }

  while (tmp) {
    node_t *del = tmp;
    tmp = tmp->next;
    free(del);
  }

  free(list);
}

void print_list(singly_linked_list_t *list) {
  node_t *tmp = list->head;

  while (tmp) {
    printf("%p ", tmp->data);
    tmp = tmp->next;
  }

  printf("\n");
}

int size(singly_linked_list_t *list) { return list->size; }

bool is_empty(singly_linked_list_t *list) { return !list->head; }

void insert_node(singly_linked_list_t *list, void *data) {
  node_t *node = create_node(data);

  if (is_empty(list)) {
    list->head = node;
  } else {
    node_t *tmp = list->head;
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = node;
  }
  list->size++;
}

bool remove_node(singly_linked_list_t *list, void *data) {
  if (is_empty(list)) {
    return false;
  }

  node_t *old = list->head, *prev;
  while (old && old->data != data) {
    prev = old;
    old = old->next;
  }

  if (!old) {
    return false;
  }

  void *removed = old->data;
  if (old == list->head) {
    list->head = list->head->next;
  } else {
    prev->next = old->next;
  }

  free(old);
  list->size--;

  return true;
}

bool search_node(singly_linked_list_t *list, void *data) {
  node_t *tmp = list->head;
  while (tmp) {
    if (tmp->data == data) {
      return true;
    }
    tmp = tmp->next;
  }

  return false;
}

// Testing
void test() {
  singly_linked_list_t *list = create_list();
  assert(is_empty(list));
  assert(size(list) == 0);

  insert_node(list, (void *)8);
  insert_node(list, (void *)12);
  insert_node(list, (void *)6);
  insert_node(list, (void *)10);

  assert(!is_empty(list));
  assert(size(list) == 4);

  assert(search_node(list, (void *)8));
  assert(!search_node(list, (void *)9));

  assert(remove_node(list, (void *)10));
  assert(remove_node(list, (void *)6));

  delete_list(list);
  printf("PASSED\n");
}

int main(int argc, const char *argv[]) {
  printf("Testing singly linked list implementation...\n");
  test();
  return 0;
}

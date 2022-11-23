#pragma once
#include <stdbool.h>
#include <stdio.h>

/**
 * Linked List is a linear data structure. Unlike arrays, linked list elements
 *  are not stored at a contiguous location the elements are linked using
 * pointers. Singly linked list is represented by a pointer to the first node
 * called head, if linked list is empty then the value of head is NULL (None).
 *  Each node of a singly linked list contains 2 parts:
 *  - Stored data
 *  - Pointer to the next node (or reference)
 *       HEAD
 *    [data1|-]->[data2|-]->[data3|-]->[data4|-]->[data5|-]->NULL
 * @tparam T node's class
 */
typedef struct Node {
  void *data;
  struct Node *next;
} node_t;

node_t *create_node(void *data);

typedef struct SinglyLinkedList {
  node_t *head;
  int size;
} singly_linked_list_t;

singly_linked_list_t *create_list();
void delete_list(singly_linked_list_t *list);
void print_list(singly_linked_list_t *list);
int size(singly_linked_list_t *list);
bool is_empty(singly_linked_list_t *list);
void insert_node(singly_linked_list_t *list, void *data);
bool remove_node(singly_linked_list_t *list, void *data);
bool search_node(singly_linked_list_t *list, void *data);

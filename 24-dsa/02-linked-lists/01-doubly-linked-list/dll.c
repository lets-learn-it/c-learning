#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

void add_first (struct dll_ *self, dll_node *node) {
  node->next = self->head;
  if (self->head)
    self->head->prev = node;
  self->head = node;
}

void print(struct dll_ *self, void (*fn)(void *data)) {
  dll_node *node = self->head;
  while(node != NULL) {
    fn(node->data);
    node = node->next;
  }
}

void add_last (struct dll_ *self, dll_node *newNode) {
  newNode->prev = self->tail;
  if (self->tail)
    self->tail->next = newNode;
  self->tail = newNode;
}

void add_next (dll_node *nextTo, dll_node *node) {
  node->next = nextTo->next;
  node->next->prev = node;
  nextTo->next = node;
  node->prev = nextTo;
}

dll_node * search (struct dll_ *self, void *key, int (*fn)(void *key, void *nodeData)) {
  dll_node *node = self->head;
  while(node != NULL) {
    if (fn(key, node->data)) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

void initialize(dll *list) {
  list->add_first = &add_first;
  list->add_last = &add_last;
  list->add_next = &add_next;
  list->print = &print;
  list->search = &search;
  list->head = NULL;
  list->tail = NULL;
}

dll_node * create_dll_node(void *data) {
  dll_node *node = malloc(sizeof(dll_node));

  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  return node;
}
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

void add_first (struct llist_ *self, llist_node *node) {
  node->next = self->head;
  self->head = node;
}

void print(struct llist_ *self, void (*fn)(void *data)) {
  llist_node *node = self->head;
  while(node != NULL) {
    fn(node->data);
    node = node->next;
  }
}

void add_last (struct llist_ *self, llist_node *newNode) {
  llist_node *node = self->head;
  
  if (node == NULL) {
    self->head = newNode;
    return;
  }
  while(node->next != NULL) {
    node = node->next;
  }
  node->next = newNode;
}

void add_next (llist_node *nextTo, llist_node *node) {
  nextTo->next = node;
}

llist_node * search (struct llist_ *self, void *key, int (*fn)(void *key, void *nodeData)) {
  llist_node *node = self->head;
  while(node != NULL) {
    if (fn(key, node->data)) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

llist_node * remove_node (struct llist_ *self, void *key, int (*fn)(void *key, void *nodeData)) {
  llist_node *node = self->head;
  llist_node *last = NULL;
  while(node != NULL) {
    if (fn(key, node->data)) {
      if (last == NULL) {  // matched at head
        self->head = node->next;
        return node;
      }
      last->next = node->next;
      return node;
    }
    last = node;
    node = node->next;
  }
  return NULL;
}

void initialize(llist *list) {
  list->add_first = &add_first;
  list->add_last = &add_last;
  list->add_next = &add_next;
  list->remove_node = &remove_node;
  list->print = &print;
  list->search = &search;
  list->head = NULL;
}

llist_node * create_llist_node(void *data) {
  llist_node *node = malloc(sizeof(llist_node));

  node->data = data;
  node->next = NULL;

  return node;
}

llist_node * copy_llist_node(llist_node *node, void *(*fn)(void *data)) {
  void *data = fn(node->data);
  llist_node *newNode = create_llist_node(data);
  return newNode;
}

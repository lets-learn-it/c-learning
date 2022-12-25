#include "ds.h"
#include <stdio.h>
#include <stdlib.h>

void add_first (struct ds_ *self, ds_node *node) {
  node->next = self->head;
  if (self->head)
    self->head->prev = node;
  self->head = node;
}

void print(struct ds_ *self, void (*fn)(void *data)) {
  ds_node *node = self->head;
  while(node != NULL) {
    fn(node->data);
    node = node->next;
  }
}

void add_last (struct ds_ *self, ds_node *newNode) {
  newNode->prev = self->tail;
  if (self->tail)
    self->tail->next = newNode;
  self->tail = newNode;
}

void add_next (ds_node *nextTo, ds_node *node) {
  node->next = nextTo->next;
  node->next->prev = node;
  nextTo->next = node;
  node->prev = nextTo;
}

ds_node * search (struct ds_ *self, void *key, int (*fn)(void *key, void *nodeData)) {
  ds_node *node = self->head;
  while(node != NULL) {
    if (fn(key, node->data)) {
      return node;
    }
    node = node->next;
  }
  return NULL;
}

ds_node * remove_last (struct ds_ *self) {
  ds_node *secondLast = self->tail->prev;
  ds_node *last = self->tail;
  self->tail = secondLast;
  secondLast->next = NULL;
  return last;
}

ds_node * remove_first (struct ds_ *self) {
  ds_node *second = self->head->next;
  ds_node *first = self->head;
  self->head = second;
  second->prev = NULL;
  return first;
}

void initialize(ds *list) {
  list->add_first = &add_first;
  list->add_last = &add_last;
  list->add_next = &add_next;
  list->push = &add_first;
  list->pop = &remove_last;
  list->enqueue = &add_last;
  list->dequeue = &remove_first;
  list->print = &print;
  list->search = &search;
  list->head = NULL;
  list->tail = NULL;
}

ds_node * create_node(void *data) {
  ds_node *node = malloc(sizeof(ds_node));

  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  return node;
}
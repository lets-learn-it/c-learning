#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

extern int DEBUG;

void push (struct stack_ *self, stack_node *node) {
  if (DEBUG) fprintf(stderr, "===== Pushing to Stack =====\n");
  node->next = self->top;
  self->top = node;
}

/* This is not valid operation but still */
void print(struct stack_ *self, void (*fn)(void *data)) {
  if (DEBUG) fprintf(stderr, "====== Printing Stack ======\n");
  stack_node *node = self->top;
  while(node != NULL) {
    fn(node->data);
    node = node->next;
  }
  if (DEBUG) fprintf(stderr, "====== Printing Ended ======\n");
}

stack_node * pop (struct stack_ *self) {
  if (DEBUG) fprintf(stderr, "===== Poping from Stack ====\n");
  stack_node *node = self->top;
  if (node != NULL) self->top = node->next;
  return node;
}

void initialize(stack *list) {
  list->push = &push;
  list->pop = &pop;
  list->print = &print;
  list->top = NULL;
}

stack_node * create_stack_node(void *data) {
  stack_node *node = malloc(sizeof(stack_node));

  node->data = data;
  node->next = NULL;

  return node;
}

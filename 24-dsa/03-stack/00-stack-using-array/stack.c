#include "stack.h"
#include <stdlib.h>

int push (struct stack_ *self, void *item) {
  if (self->top >= self->size) return -1;
  self->top++;
  self->arr[self->top] = item;
  return 0;
}

void* pop (struct stack_ *self) {
  if (self->top < 0) return NULL;
  void *item = self->arr[self->top];
  self->top--;
  return item;
}

void* stacktop (struct stack_ *self) {
  return self->arr[self->top];
}

// printing stack without removing elements
// not a valid operation, but still
void print(struct stack_ *self, void (*fn)(void *data)) {
  int current = self->top;
  while(current >= 0) {
    fn(self->arr[current]);
    current --;
  }
}

int initialize (stack *s, int size) {
  s->size = size;
  s->top = -1;
  s->arr = malloc(sizeof(void *) * size);
  s->push = &push;
  s->pop = &pop;
  s->stacktop = &stacktop;
  s->print = &print;
  return 0;
}

int destroy (stack *self) {
  free(self);
  return 0;
}
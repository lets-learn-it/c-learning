#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int enqueue (struct queue_ *self, void *item) {
  // check if queue is full
  if (self->elements == self->size) return -1;

  self->arr[self->end] = item;
  self->end = (self->end + 1)%self->size;
  self->elements ++;

  return 0;
}

void* dequeue (struct queue_ *self) {
  // check if queue is empty
  if (self->elements == 0) return NULL;

  void *item = self->arr[self->start];
  self->start = (self->start + 1) % self->size;
  self->elements --;
  return item;
}

void* front (struct queue_ *self) {
  if (self->elements <= 0) return NULL;
  
  return self->arr[self->start];
}

/* 
 * has bug when queue is full (start == end)
 */
void print (struct queue_ *self, void (*fn) (void *data)) {
  int i = 0;
  while(i < self->elements) {
    fn(self->arr[self->start + i]);
    i++;
  }
}

int initialize (queue *self, int size) {
  self->start = 0;
  self->end = 0;
  self->size = size;
  self->arr = malloc(sizeof(void*) * size);
  self->elements = 0;
  self->enqueue = &enqueue;
  self->dequeue = &dequeue;
  self->front = &front;
  self->print = &print;
  return 0;
}

int destroy (queue *self) {

}
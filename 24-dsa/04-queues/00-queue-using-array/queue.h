
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue_ {
  // start is front & end is back
  int start, end;

  // total elements in queue
  // this is needed for full & empty queue identification
  int elements;

  // maximum elements queue can hold
  int size;
  void **arr;

  int (*enqueue) (struct queue_ *self, void *item);
  void* (*dequeue) (struct queue_ *self);
  void* (*front) (struct queue_ *self);
  void (*print) (struct queue_ *self, void (*fn) (void *data));
} queue;

int initialize (queue *s, int size);
int destroy (queue *self);

#endif
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

extern int DEBUG;

void enqueue (struct queue_ *self, queue_node *node) {
  if (DEBUG) fprintf(stderr, "===== Pushing to Queue =====\n");

  if (self->front == NULL) self->front = node;
  else self->back->next = node;
  
  self->back = node;
}

void print(struct queue_ *self, void (*fn)(void *data)) {
  if (DEBUG) fprintf(stderr, "====== Printing Queue ======\n");
  queue_node *node = self->front;
  while(node != NULL) {
    fn(node->data);
    node = node->next;
  }
  if (DEBUG) fprintf(stderr, "====== Printing Ended ======\n");
}


queue_node * dequeue (struct queue_ *self) {
  if (DEBUG) fprintf(stderr, "===== Poping from Queue ====\n");
  queue_node *node = self->front;
  if (node != NULL) self->front = node->next;
  return node;
}

queue_node * get_front (struct queue_ *self) {
  return self->front;
}

void initialize(queue *q) {
  q->enqueue = &enqueue;
  q->dequeue = &dequeue;
  q->print = &print;
  q->get_front = &get_front;
  q->front = NULL;
  q->back = NULL;
}

queue_node * create_queue_node(void *data) {
  queue_node *node = malloc(sizeof(queue_node));

  node->data = data;
  node->next = NULL;

  return node;
}


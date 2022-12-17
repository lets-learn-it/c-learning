
#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack_ {
  int top;
  int size;
  void **arr;

  int (*push) (struct stack_ *self, void *item);
  void* (*pop) (struct stack_ *self);
  void* (*stacktop) (struct stack_ *self);
  void (*print) (struct stack_ *self, void (*fn) (void *data));
} stack;

int initialize (stack *s, int size);
int destroy (stack *self);

#endif

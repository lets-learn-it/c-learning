# Queue using array

![queue using array](./array-as-queue.svg)

## Operations

```c
int (*enqueue) (struct queue_ *self, void *item);
void* (*dequeue) (struct queue_ *self);
void* (*front) (struct queue_ *self);
void (*print) (struct queue_ *self, void (*fn) (void *data));
```
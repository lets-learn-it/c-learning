# Stack using array

![stack using array](./array-as-stack.svg)

## Operations

```c
int (*push) (struct stack_ *self, void *item);
void* (*pop) (struct stack_ *self);
void* (*stacktop) (struct stack_ *self);
void (*print) (struct stack_ *self, void (*fn) (void *data));
```
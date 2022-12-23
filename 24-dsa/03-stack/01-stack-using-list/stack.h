
typedef struct stack_node_ {
  struct stack_node_ *next;
  void *data;
} stack_node;

typedef struct stack_ {
  stack_node *top;

  /* functions */
  void (*push) (struct stack_ *self, stack_node *node);
  stack_node * (*pop) (struct stack_ *self);
  void (*print) (struct stack_ *self, void (*fn) (void *data));
} stack;

void initialize(stack *list);
stack_node * create_stack_node(void *data);


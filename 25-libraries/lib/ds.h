
typedef struct ds_node_ {
  struct ds_node_ *next, *prev;
  void *data;
} ds_node;

typedef struct ds_ {
  ds_node *head, *tail;

  /* functions */
  void (*add_first) (struct ds_ *self, ds_node *node);
  void (*add_last) (struct ds_ *self, ds_node *node);
  void (*add_next) (ds_node *nextTo, ds_node *node);     
  void (*push) (struct ds_ *self, ds_node *node);        /* stack push */
  ds_node * (*pop) (struct ds_ *self);                   /* stack pop */
  void (*enqueue) (struct ds_ *self, ds_node *node);     /* queue push */
  ds_node * (*dequeue) (struct ds_ *self);               /* queue remove */
  ds_node * (*search) (struct ds_ *self, void *data, int (*fn)(void *data, void *nodeData));
  void (*print) (struct ds_ *self, void (*fn) (void *data));
} ds;

void initialize(ds *list);
ds_node * create_node(void *data);

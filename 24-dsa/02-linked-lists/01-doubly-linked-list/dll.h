
typedef struct dll_node_ {
  struct dll_node_ *next, *prev;
  void *data;
} dll_node;

typedef struct dll_ {
  dll_node *head, *tail;

  /* functions */
  void (*add_first) (struct dll_ *self, dll_node *node);
  void (*add_last) (struct dll_ *self, dll_node *node);
  void (*add_next) (dll_node *nextTo, dll_node *node);
  int (*remove) (struct dll_ *self, dll_node *node);
  dll_node * (*search) (struct dll_ *self, void *data, int (*fn)(void *data, void *nodeData));
  void (*print) (struct dll_ *self, void (*fn) (void *data));
} dll;

void initialize_dll(dll *list);
dll_node * create_dll_node(void *data);

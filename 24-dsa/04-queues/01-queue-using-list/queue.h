
typedef struct queue_node_ {
  struct queue_node_ *next;
  void *data;
} queue_node;

typedef struct queue_ {
  queue_node *front;
  queue_node *back;

  /* functions */
  void (*enqueue) (struct queue_ *self, queue_node *node);
  queue_node * (*dequeue) (struct queue_ *self);
  queue_node * (*get_front) (struct queue_ *self);
  void (*print) (struct queue_ *self, void (*fn) (void *data));
} queue;

void initialize(queue *queue);
queue_node * create_queue_node(void *data);


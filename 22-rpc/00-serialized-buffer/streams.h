
#define SERIALIZE_BUFFER_DEFAULT_SIZE 100

typedef struct serialized_buffer {
  char *b;    /* points to start of the memory buffer which actually stores data */
  int size;   /* size of serialized buffer */
  int next;   /* byte position in serialized buffer where next data item will be written into or read from */
} ser_buff_t;

void init_serialized_buffer (ser_buff_t **b);
void serialize_data (ser_buff_t *buff, char *data, int nbytes);
void de_serialize_data (char *dest, ser_buff_t *b, int size);
void serialize_buffer_skip (ser_buff_t *b, int skip_size);
void free_serialize_buffer (ser_buff_t *b);

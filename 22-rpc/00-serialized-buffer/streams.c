#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "streams.h"

void init_serialized_buffer (ser_buff_t **b) {
  (*b) = (ser_buff_t *) calloc(1, sizeof(ser_buff_t));

  /* create buffer */
  (*b)->b = calloc(1, SERIALIZE_BUFFER_DEFAULT_SIZE);

  (*b)->size = SERIALIZE_BUFFER_DEFAULT_SIZE;

  (*b)->next = 0;
}

void serialize_data (ser_buff_t *buff, char *data, int nbytes) {
  int available_size = buff->size - buff->next;
  bool isResize = 0;

  /* dont know why */
  while (available_size < nbytes) {
    buff->size = buff->size * 2;
    available_size = buff->size - buff->next;
    isResize = 1;
  }

  if (isResize) {
    buff->b = realloc(buff->b, buff->size);
  }

  memcpy((char *)buff->b + buff->next, data, nbytes);
  buff->next += nbytes;
  return;
}

void de_serialize_data (char *dest, ser_buff_t *b, int size) {
  memcpy(dest, b->b + b->next, size);
  b->next += size;
  return;
}

void serialize_buffer_skip (ser_buff_t *b, int skip_size) {
  if (b->next + skip_size > 0 && b->next + skip_size < b->size)
    b->next += skip_size;
  return;
}

void free_serialize_buffer (ser_buff_t *b) {
  free(b);
  return;
}

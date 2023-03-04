#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "streams.h"

#define info(...) fprintf(stdout, __VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)
#define bufn(b, n) for (int i = 0; i < n; i++) err("%02X ", (unsigned char) *(b + i))


struct person {
  uint16_t salary;
  uint8_t age;
  char name[20];
};


int main(int argc, char const *argv[]) {
  ser_buff_t *stream;
  init_serialized_buffer(&stream);

  /* create object of person */
  struct person p1;
  p1.age = 25;
  strcpy(p1.name, "Parikshit");
  p1.salary = 12345;

  /* serialize */
  serialize_data(stream, (char *) &p1.age, sizeof(p1.age));
  serialize_data(stream, p1.name, sizeof(p1.name));
  serialize_data(stream, (char *) &p1.salary, sizeof(p1.salary));

  bufn(stream->b, stream->next);

  // reset next to 0
  stream->next = 0;

  struct person p2;

  /* deserialize */
  de_serialize_data((char *) &p2.age, stream, sizeof(p2.age));
  de_serialize_data(p2.name, stream, sizeof(p2.name));
  de_serialize_data((char *) &p2, stream, sizeof(p2.salary));

  err("\n%s\n", p2.name);
  err("%d\n", p2.age);
  err("%d\n", p2.salary);
  return 0;
}


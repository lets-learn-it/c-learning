#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

typedef struct Person {
  int age;
  char *name;
} Person;

Person * get_person(char *name, int age) {
  Person *person = malloc(sizeof(Person));
  person->age = age;
  person->name = name;
  return person;
}

void print_fn(void *data) {
  Person *person = (Person *) data;
  fprintf(stdout, "%d %s\n", person->age, person->name);
}

int main(int argc, char const *argv[]) {
  int status = 0;
  queue q;
  initialize(&q, 3);

  void *p1 = (void *) get_person("XYZ", 52);
  q.enqueue(&q, p1);

  void *p2 = (void *) get_person("Parikshit", 25);
  q.enqueue(&q, p2);

  void *p3 = (void *) get_person("ABC", 32);
  q.enqueue(&q, p3);

  void *p4 = (void *) get_person("PQR", 120);
  q.enqueue(&q, p4);

  // print stack
  q.print(&q, &print_fn);

  // pop
  q.dequeue(&q);
  q.dequeue(&q);

  // print stack
  q.print(&q, &print_fn);

  print_fn(q.front(&q));

  // destroy has issue
  // destroy(&s);
  return 0;
}

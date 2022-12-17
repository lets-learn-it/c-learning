#include <stdio.h>
#include "stack.h"
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
  stack s;
  initialize(&s, 10);

  void *p1 = (void *) get_person("XYZ", 52);
  s.push(&s, p1);

  void *p2 = (void *) get_person("Parikshit", 25);
  s.push(&s, p2);

  void *p3 = (void *) get_person("ABC", 32);
  s.push(&s, p3);

  void *p4 = (void *) get_person("PQR", 120);
  s.push(&s, p4);

  // print stack
  s.print(&s, &print_fn);

  // pop
  s.pop(&s);

  // print stack
  s.print(&s, &print_fn);

  print_fn(s.stacktop(&s));

  // destroy has issue
  // destroy(&s);
  return 0;
}

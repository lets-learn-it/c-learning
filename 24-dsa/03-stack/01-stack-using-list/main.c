#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int DEBUG = 0;

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
  if (argc > 1 && strcmp(argv[1], "-d") == 0) {
    DEBUG = 1;
  }

  stack s;
  initialize(&s);

  stack_node *node2 = create_stack_node((void *) get_person("XYZ", 52));
  s.push(&s, node2);

  stack_node *node1 = create_stack_node((void *) get_person("Parikshit", 25));
  s.push(&s, node1);

  stack_node *node3 = create_stack_node((void *) get_person("ABC", 32));
  s.push(&s, node3);

  stack_node *node4 = create_stack_node((void *) get_person("PQR", 120));
  s.push(&s, node4);

  s.print(&s, &print_fn);

  s.pop(&s);

  s.print(&s, &print_fn);

  s.pop(&s);s.pop(&s);

  s.print(&s, &print_fn);

  s.pop(&s);s.pop(&s);

  return 0;
}
#include "gldll.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* inbuilt offsetof */
#include <stddef.h>

typedef struct Person {
  int age;
  char *name;

  /* node */
  gldll_node_t glnode;
} Person;

Person * get_person(char *name, int age) {
  Person *person = malloc(sizeof(Person));
  person->age = age;
  person->name = name;
  person->glnode.left = NULL;
  person->glnode.right = NULL;
  return person;
}

void print_fn(gldll_node_t *node) {
  int offset = offsetof(Person, glnode);

  Person *person = (Person *) ((char *) node - offset);

  fprintf(stdout, "%d %s\n", person->age, person->name);
}

int main(int argc, char const *argv[]) {
  gldll_t list;
  list.head = NULL;       // avoid garbage

  gldll_node_t *node2 = &(get_person("XYZ", 52)->glnode);
  gldll_add(&list, node2);

  gldll_node_t *node1 = &(get_person("Parikshit", 25)->glnode);
  gldll_add(&list, node1);

  gldll_node_t *node3 = &(get_person("ABC", 32)->glnode);
  gldll_add(&list, node3);

  gldll_node_t *node4 = &(get_person("PQR", 120)->glnode);
  gldll_add(&list, node4);

  print(&list, &print_fn);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "ds.h"         /* make sure add includepath "25-libraries/lib" */

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

void * copy_person(void *data) {
  Person *person = (Person *) data;
  Person *newPerson = malloc(sizeof(Person));
  newPerson->age = 100;
  newPerson->name = person->name;
  return (void *) newPerson;
}

void print_fn(void *data) {
  Person *person = (Person *) data;
  fprintf(stdout, "%d %s\n", person->age, person->name);
}

int searcher(void *key, void *data) {
  Person *person = (Person *) data;
  int age = *(int *)key;
  if(person->age == age) {
    return 1;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  ds list;
  initialize(&list);

  ds_node *node2 = create_node((void *) get_person("XYZ", 52));
  list.add_last(&list, node2);

  ds_node *node1 = create_node((void *) get_person("Parikshit", 25));
  list.add_first(&list, node1);

  ds_node *node3 = create_node((void *) get_person("ABC", 32));
  list.add_first(&list, node3);

  ds_node *node4 = create_node((void *) get_person("PQR", 120));
  list.add_last(&list, node4);

  list.print(&list, &print_fn);

  int x = 120;
  ds_node *node = list.search(&list, (void *) &x, &searcher);
  if (node != NULL) {
    fprintf(stdout, "== %d\n", ((Person *)node->data)->age);
  }
  fprintf(stdout, "-----\n");

  list.pop(&list);

  list.print(&list, &print_fn);

  return 0;
}
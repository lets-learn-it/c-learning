#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

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
  llist list;
  initialize(&list);

  llist_node *node2 = create_llist_node((void *) get_person("XYZ", 52));
  list.add_last(&list, node2);

  llist_node *copied_node2 = copy_llist_node(node2, &copy_person);
  list.add_next(node2, copied_node2);

  llist_node *node1 = create_llist_node((void *) get_person("Parikshit", 25));
  list.add_first(&list, node1);

  llist_node *node3 = create_llist_node((void *) get_person("ABC", 32));
  list.add_first(&list, node3);

  llist_node *node4 = create_llist_node((void *) get_person("PQR", 120));
  list.add_last(&list, node4);

  list.print(&list, &print_fn);

  int x = 120;
  llist_node *node = list.search(&list, (void *) &x, &searcher);
  if (node != NULL) {
    fprintf(stdout, "== %d\n", ((Person *)node->data)->age);
  }
  fprintf(stdout, "-----\n");
  list.remove_node(&list, (void *) &x, &searcher);

  list.print(&list, &print_fn);

  return 0;
}
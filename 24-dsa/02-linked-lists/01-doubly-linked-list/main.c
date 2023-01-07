#include <stdio.h>
#include "dll.h"

typedef struct Person {
  int age;
  char *name;
} Person;


void print_fn(void *data) {
  Person *person = (Person *) data;
  fprintf(stdout, "Person { name: %s, age: %d }\n", person->name, person->age);
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
  
  dll list;
  initialize_dll(&list);

  Person p1;
  p1.age = 25;
  p1.name = "Parikshit";
  dll_node *node1 = create_dll_node((void *) &p1);
  list.add_first(&list, node1);

  Person p2;
  p2.age = 40;
  p2.name = "XYZ";
  dll_node *node2 = create_dll_node((void *) &p2);
  list.add_first(&list, node2);

  Person p3;
  p3.age = 46;
  p3.name = "Some old Guy";
  dll_node *node3 = create_dll_node((void *) &p3);
  list.add_first(&list, node3);

  list.print(&list, &print_fn);

  int x = 25;
  dll_node *node = list.search(&list, (void *) &x, &searcher);
  if (node != NULL) {
    fprintf(stdout, "Searched : %d Removing...\n", ((Person *)node->data)->age);

    // remove searched node
    list.remove(&list, node);
    list.print(&list, &print_fn);
  }

  return 0;
}
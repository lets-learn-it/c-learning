#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tree.h"

int DEBUG = 1;

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
  
  Tree tree;
  initialize_tree(&tree);

  Person p1;
  p1.age = 25;
  p1.name = "Parikshit";
  TreeNode *node1 = create_tree_node((void *) &p1);
  tree.add(&tree, NULL, node1); /* root */

  Person p2;
  p2.age = 40;
  p2.name = "XYZ";
  TreeNode *node2 = create_tree_node((void *) &p2);
  tree.add(&tree, node1, node2);

  // Person p3;
  // p3.age = 46;
  // p3.name = "Some old Guy";
  // dll_node *node3 = create_dll_node((void *) &p3);
  // tree.add_first(&tree, node3);

  tree.print(&tree, &print_fn);

  

  return 0;
}

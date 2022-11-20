#include <stdio.h>
#include <dll.h>

typedef struct Person {
  int age;
} Person;


void print_fn(void *data) {
  Person *person = (Person *) data;
  fprintf(stdout, "%d ", person->age);
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
  initialize(&list);

  Person p1;
  p1.age = 25;
  dll_node *node1 = create_node((void *) &p1);
  list.add_first(&list, node1);

  Person p2;
  p2.age = 40;
  dll_node *node2 = create_node((void *) &p2);
  list.add_first(&list, node2);

  Person p3;
  p3.age = 46;
  dll_node *node3 = create_node((void *) &p3);
  list.add_first(&list, node3);

  list.print(&list, &print_fn);

  int x = 46;
  dll_node *node = list.search(&list, (void *) &x, &searcher);
  if (node != NULL) {
    fprintf(stdout, "%d", ((Person *)node->data)->age);
  }
  return 0;
}
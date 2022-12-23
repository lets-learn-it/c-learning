#define ALLOW_DEBUG

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
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
  if (argc > 1 && strcmp(argv[1], "-d") == 0) {
    DEBUG = 1;
  }

  queue q;
  initialize(&q);

  queue_node *node2 = create_queue_node((void *) get_person("XYZ", 52));
  q.enqueue(&q, node2);

  queue_node *node1 = create_queue_node((void *) get_person("Parikshit", 25));
  q.enqueue(&q, node1);

  queue_node *node3 = create_queue_node((void *) get_person("ABC", 32));
  q.enqueue(&q, node3);

  queue_node *node4 = create_queue_node((void *) get_person("PQR", 120));
  q.enqueue(&q, node4);

  q.print(&q, &print_fn);

  q.dequeue(&q);

  q.print(&q, &print_fn);

  q.dequeue(&q);q.dequeue(&q);

  q.print(&q, &print_fn);

  q.dequeue(&q);q.dequeue(&q);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "BST.h"

int DEBUG = 0;

typedef struct person {
  int id;
  char *name;
} Person;

int compare(void *existing_key, void *new_key) {
  int *p1 = (int *) existing_key;
  int *p2 = (int *) new_key;
  if (*p2 < *p1) return -1;
  if (*p2 > *p1) return 1;
  return 0;
}

void print_person(void *key, void *value) {
  Person *p = (Person *) value;
  int *k = (int *) key;
  printf("Key: %d, Value: Person { id: %d, name: %s }\n", *k, p->id, p->name);
}

int main() {
  BST bst;
  initialize_bst(&bst, &compare);

  Person p1 = {55, "p1"};
  Person p2 = {3, "p2"};
  Person p3 = {300, "p3"};
  Person p4 = {1, "p4"};
  Person p5 = {10, "p5"};
  Person p6 = {100, "p6"};
  Person p7 = {555, "p7"};

  BSTNode *n1 = create_bst_node((void *) &p1.id, (void *) &p1);
  BSTNode *n2 = create_bst_node((void *) &p2.id, (void *) &p2);
  BSTNode *n3 = create_bst_node((void *) &p3.id, (void *) &p3);
  BSTNode *n4 = create_bst_node((void *) &p4.id, (void *) &p4);
  BSTNode *n5 = create_bst_node((void *) &p5.id, (void *) &p5);
  BSTNode *n6 = create_bst_node((void *) &p6.id, (void *) &p6);
  BSTNode *n7 = create_bst_node((void *) &p7.id, (void *) &p7);

  bst.insert(&bst, n1);
  bst.insert(&bst, n2);
  bst.insert(&bst, n3);
  bst.insert(&bst, n4);
  bst.insert(&bst, n5);
  bst.insert(&bst, n6);
  bst.insert(&bst, n7);

  bst.inorder(&bst, &print_person);

  printf("===========================\n");

  bst.delete_node(n3);
  bst.inorder(&bst, &print_person);

  return 0;
}
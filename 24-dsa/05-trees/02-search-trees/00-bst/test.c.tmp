#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "BST.h"

int DEBUG = 0;

int test_compare(void *existing_key, void *new_key) {
  int *p1 = (int *) existing_key;
  int *p2 = (int *) new_key;
  if (*p2 < *p1) return -1;
  if (*p2 > *p1) return 1;
  return 0;
}

void print_int(void *key, void *value) {
  int *v = (int *) value;
  int *k = (int *) key;
  printf("Key: %d, Value: %d\n", *k, *v);
}

int main() {
  BST bst;
  initialize_bst(&bst, &test_compare);

  int counter = 1, elements = 1000000;
  srand(time(NULL));

  // clock_t start, end;
  int *k = NULL;
  int *v = NULL;

  // double prep, insert, find;

  // clock_t pstart, pend;
  // pstart = clock();

  while(counter <= elements) {
    // start = clock();
    k = malloc(sizeof(int));
    v = malloc(sizeof(int));
    *k = *v = rand();
    BSTNode *n = create_bst_node((void *) k, (void *) v);
    // end = clock();

    // prep = ((double)(end - start) / CLOCKS_PER_SEC);

    // start = clock();
    bst.insert(&bst, n);
    // end = clock();
    // insert = ((double)(end - start) / CLOCKS_PER_SEC);

    // find
    // start = clock();
    bool found = bst.find(&bst, k);
    // end = clock();
    // find = ((double)(end - start) / CLOCKS_PER_SEC);

    // printf("%d,%f,%f,%f,%d,%d\n", counter, prep*1000, insert*1000, find*1000, *k, found);
    counter++;
  }

  // pend = clock();
  // double total = ((double)(pend - pstart) / CLOCKS_PER_SEC);
  // printf("Total: %f", total);

  return 0;
}
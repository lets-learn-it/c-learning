#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int *x;

void* incrementX() {
  (*x)++;
  fprintf(stdout, "in: Value: %d & Address: %p\n", *x, &(*x));
}

void* showX() {
  fprintf(stdout, "show: Value: %d & Address: %p\n", *x, &(*x));
}

int main(int argc, char const *argv[]) {
  x = malloc(sizeof(int));

  *x = 2;

  pthread_t t1, t2;

  // we should check return value but forgot it now
  // Value of x depends on which thread prints it first
  pthread_create(&t1, NULL, &incrementX, NULL);
  pthread_create(&t2, NULL, &showX, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
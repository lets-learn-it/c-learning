#include<stdio.h>
#include<stdlib.h>

/* 
  Notes:
  - memory allocated by malloc can be reduced or increased
  - Data may be moved to another location where enough continous memory available
 */

int main() {
  int *a = (int*) malloc(sizeof(int));

  *a = 10;

  printf("Before realloc: addr %p val %d\n", a, *a);

  a = (int*) realloc(a, 2*sizeof(int));

  printf("After realloc: addr %p val %d\n", a, *a);

  *(a+1) = 17;
  printf("After realloc: addr %p val %d\n", a+1, *(a+1));

  return 0;
}
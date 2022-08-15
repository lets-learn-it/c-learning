#include<stdio.h>
#include<stdlib.h>

/* 
  Notes:
  - free(ptr); where ptr is pointer to memory which is allocated by malloc/calloc/realloc
  - Memory pointed by pointer getting released not pointer
  - in case of calloc, no need to free each element
 */

int main() {
  int *a = (int*) malloc(sizeof(int));

  *a = 10;

  printf("Before free: addr %p val %d\n", a, *a);

  free(a);

  printf("After free: addr %p val %d\n", a, *a);

  return 0;
}
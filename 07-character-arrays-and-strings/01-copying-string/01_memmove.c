#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* 
 * Use clang because gcc works correctly 
 */

int main(int argc, char const *argv[]) {
  char a1[] = "Hi There  ";
  char a2[] = "Hi There  ";

  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);

  // using memcpy
  memcpy(a1+3, a1, 5);

  // using memmove
  memmove(a2+3, a2, 5);

  printf("a1 (f**ked up): %s\n", a1);
  printf("a2 (correct..): %s\n", a2);

  return 0;
}

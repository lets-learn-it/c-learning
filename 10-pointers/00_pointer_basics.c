#include <stdio.h>

int main(int argc, char const* argv[]) {
  int n = 10;

  // get a pointer to n
  int* p1 = &n;    // p1 -> address of n
  int** p2 = &p1;  // p2 -> address of p1
  printf("Addr(n): %p, Addr(p1): %p, Addr(p2): %p\n", &n, &p1, &p2);
  printf("Val(n): %d, Val(p1): %p, Val(p2): %p\n", n, p1, p2);

  char* name = "Parikshit";
  printf("name: %p, name(1st letter): %c, name(2nd letter): %c\n", name, *name,
         *(name + 1));
  return 0;
}

#include <stdio.h>

int main(int argc, char const *argv[]) {
  const int a = 25;

  // try to change a
  // a = 45;

  // but can be changed
  int *b = &a;
  *b = 56;
  
  printf("%d", a);
  return 0;
}

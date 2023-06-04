#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int n = 0b1100111010;
  int mask, i, j;

  /* Clear Last i bits */
  i = 4;
  mask = ((~0)<<i);
  printf("Clear Last i bits: %b after %b (mask %b)\n", n, (n&mask), mask);

  /* Clear i to j bits */
  i = 6;
  j = 1;
  mask = ((~0)<<(i+1))|((1<<j)-1);
  printf("Clear Last i bits: %b after %b (mask %b)\n", n, (n&mask), mask);
  
  return 0;
}

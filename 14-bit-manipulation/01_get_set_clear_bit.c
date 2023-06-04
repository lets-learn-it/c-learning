#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int n = 0b00111010;
  int mask, i;

  /* Get ith bit */
  i = 1;
  mask = (1<<i);
  printf("Get ith bit: %d th bit is %d (mask %b)\n", i, (n&mask) > 0, mask);

  /* Set ith bit */
  i=2;
  mask = (1<<i);
  printf("Set ith bit: %b after %b (mask %b)\n", n, n|mask, mask);

  /* Clear ith bit */
  i=1;
  mask = ~(1<<i);
  printf("Clear ith bit: %b after %b (mask %b)\n", n, n&mask, mask);
  return 0;
}

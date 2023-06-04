#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i = 0;

  /* Output should be 3 2 1 */
  printf("%d %d %d", ++i, ++i, ++i);
  return 0;
}

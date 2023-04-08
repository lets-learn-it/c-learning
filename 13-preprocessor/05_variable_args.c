#include <stdio.h>
#include <stdlib.h>

#define SUM(a, ...) #__VA_ARGS__

int main(int argc, char const *argv[]) {
  printf("%s", SUM(1,2,3,4,5,6,7,8,9,10));

  return 0;
}

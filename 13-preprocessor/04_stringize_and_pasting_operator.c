#include <stdlib.h>
#include <stdio.h>

#define NAME(s) #s
#define FULLNAME(a,b) a ## b

int main(int argc, char const *argv[]) {
  printf(NAME(abc xyz));

  int xy = 1;
  printf("%d", FULLNAME(x, y));
  return 0;
}

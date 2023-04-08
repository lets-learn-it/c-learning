#include <stdio.h>
#include <stdlib.h>

#define INDIA 1
#define US 2

#define COUNTRY INDIA

int main(int argc, char const *argv[]) {
  printf("Code for Universe\n");

#if COUNTRY == INDIA
  printf("Code for India\n");
#elif COUNTRY == US
  printf("Code for US\n");
#else
  printf("Code for others\n");
#endif

  return 0;
}

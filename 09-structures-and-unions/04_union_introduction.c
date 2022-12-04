#include <stdio.h>
#include <string.h>

union Data {
  int i;
  float f;
  char str[20];
};

int main(int argc, char const *argv[]) {
  union Data data;

  printf("Memory: %ld\n", sizeof data);

  data.i = 10;
  data.f = 10.5;

  // data of int is corrupted
  printf("data i: %d\n", data.i);
  printf("data f: %f\n", data.f);

  printf("data str: %s\n", data.str);

  strcpy(data.str, "This is demo");

  printf("data i: %d\n", data.i);
  printf("data f: %f\n", data.f);
  printf("data str: %s\n", data.str);
  return 0;
}

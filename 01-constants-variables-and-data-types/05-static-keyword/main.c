#include <stdio.h>

int main(int argc, char const *argv[]) {
  // this wont work
  extern int age;
  printf("%d", age);

  // This wont work either
  extern int get_age();
  printf("%d", get_age());

  // this will work
  extern int pls_call_get_age();
  printf("%d", pls_call_get_age());
  return 0;
}

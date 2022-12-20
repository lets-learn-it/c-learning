#include <stdio.h>

int get_next_number() {
  static int num = 0;
  return num++;
}

int main(int argc, char const *argv[]) {
  // this wont work
  extern int age;
  printf("%d", age);

  // This wont work either
  extern int get_age();
  printf("%d", get_age());

  // this will work
  extern int pls_call_get_age();
  printf("%d\n", pls_call_get_age());

  for (int i=0;i<5;i++)
    printf("%d ", get_next_number());
  return 0;
}

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 25;
  int b = 50;

  // pointer to constant
  const int *c = &a;
  int const *d = &b;

  // can't change value of c & d
  // but they can refer to other memory
  // *c = 60;
  // *d = 70;
  printf("c = %d, d = %d\n", *c, *d);

  c = &b;
  d = &a;
  printf("c = %d, d = %d\n", *c, *d);
  
  // constant pointer
  int *const e = &a;

  // cant point to another location
  // e = &b;
  printf("e = %d\n", *e);

  *e = 70;
  printf("e = %d\n", *e);


  // both pointer is constant & value
  const int *const f = &a;

  // cant change where pointer is pointing
  // f = &b;

  // cant change value of it
  // *f = 80;

  printf("f = %d\n", *f);

  return 0;
}

#include <stdio.h>

/*
 * `const` applies to what is immediately on its left; if there is nothing on
 * the left, it applies to what is on its right.
 */

int main(int argc, char const* argv[]) {
  int n = 10;
  int m = 20;

  // CASE 1: int is const not pointer
  const int* p1 = &n;
  int const* p2 = &n;  // both of these are same
  // *p1 = 30;  // expression must be a modifiable lvalue
  p1 = &m;
  printf("p1 should be pointing to m (20): %d\n", *p1);

  // CASE 2: pointer is const not underlying variable
  int* const p3 = &n;
  // p3 = &m;  // expression must be a modifiable lvalue
  *p3 = 34;
  printf("p3 should change value of n. *p3 = %d, n = %d\n", *p3, n);

  // CASE 3: both pointer & underlying value are const
  const int* const p4 = &n;
  int const* const p5 = &n;
  // *p4 = 45;    // expression must be a modifiable lvalue
  // p4 = &m;     // expression must be a modifiable lvalue

  // CASE 4: original int is const
  const int n1 = 45;
  // n1 = 56;              // expression must be a modifiable lvalue
  int* p6 = &n1;
  *p6 = 34;  // this will change n1
  printf("Val(p6): %d, Val(n1): %d\n", *p6, n1);

  return 0;
}

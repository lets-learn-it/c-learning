#include <stdio.h>

int sum(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

// passing function pointer to function
int do_op(int (*op) (int, int), int a, int b) {
  return op(a,b);
}

int main(int argc, char const *argv[]) {
  // returntype (*name) (args)
  int (*op1) (int, int) = &sum;
  int (*op2) (int, int) = &subtract;

  fprintf(stdout, "4 + 5 = %d\n", op1(4,5));

  fprintf(stdout, "do_op 4 + 5 = %d\n", do_op(op1,4,5));
  fprintf(stdout, "do_op 4 - 5 = %d\n", do_op(&subtract,4,5));

  return 0;
}

#include <stdlib.h>
#include <stdio.h>

#define PI 3.14
#define SQUARE(x) x*x

int main(int argc, char const *argv[]) {
  printf("square of PI: %f\n", SQUARE(PI));
  printf("sqaure of 2: %d\n", SQUARE(2));
  return 0;
}

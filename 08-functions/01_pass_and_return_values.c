#include<stdio.h>

int add(int a, int b);

int main() {
  int a = 10;
  int b = 45;

  int c = add(a, b);

  printf("%d + %d = %d\n", a, b, c);
  return 0;
}

int add(int a, int b) {
  return a + b;
}
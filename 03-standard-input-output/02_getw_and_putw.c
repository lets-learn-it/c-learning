#include<stdio.h>

// getw & putw are same as getc & putc
// only diffence is getw/putw works with word while
// getc/putc works with byte

int main() {
  int a;

  a = getw(stdin);

  putw(a, stdout);

  return 0;
}
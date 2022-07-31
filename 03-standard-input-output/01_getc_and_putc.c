#include<stdio.h>

// getc & putc can be used with other kind of stream
// like files.

int main() {
  char a;

  // getc return integer ASCII
  a = getc(stdin);

  putc(a, stdout);

  return 0;
}
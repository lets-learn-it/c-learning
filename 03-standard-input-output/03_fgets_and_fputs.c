#include<stdio.h>

int main() {
  char s[20];

  // fgets() reads in at most one less than size characters from stream
  fgets(s, 6, stdin);

  fputs(s, stdout);

  return 0;
}
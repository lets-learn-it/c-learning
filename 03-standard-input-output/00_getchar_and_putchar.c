#include<stdio.h>

int main() {
  char a;

  // accepts any character keyed in
  // including RETURN & TAB
  // getchar internally uses getc
  a = getchar();

  // putchar internally uses putc
  putchar(a);

  // read first 5 chars
  char chars[5];

  for(int i=0;i<5;i++)
    chars[i] = getchar();

  for(int i=0;i<5;i++)
    putchar(chars[i]);
    
  return 0;
}
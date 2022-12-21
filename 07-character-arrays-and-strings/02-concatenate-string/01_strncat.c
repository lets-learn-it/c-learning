#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  char s1[] = "Hi There  ";
  char s2[] = "Hi There, I am longer one";

  char dest[100];

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  strncat(dest, s1, strlen(s1));
  strncat(dest, s2, 5);

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("dest: %s\n", dest);

  return 0;
}

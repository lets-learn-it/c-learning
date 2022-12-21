#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  char s1[] = "Hi There  ";
  char s2[] = "Hi There, I am longer one";

  char d1[15];
  char d2[15];

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  // using strcpy
  strcpy(d1, s1);

  printf("d1: %s\n", d1);
  
  // source is longer
  strcpy(d2, s2);

  printf("d2 (len %lu): %s\n", strlen(d2), d2);

  return 0;
}

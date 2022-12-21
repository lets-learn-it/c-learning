#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  char s1[] = "Hi There  ";
  char s2[] = "Hi There, I am longer one";

  int DESTINATION_BUFFER = 15;
  char d1[DESTINATION_BUFFER];
  char d2[DESTINATION_BUFFER];

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  // using strncpy
  strncpy(d1, s1, DESTINATION_BUFFER);

  printf("d1: %s\n", d1);
  
  // source is longer
  // destination will not overflow
  strncpy(d2, s2, DESTINATION_BUFFER);

  printf("d2 (len %lu): %s\n", strlen(d2), d2);

  return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char s1[] = "This is demo";
  char s2[] = "This is demo";
  char s3[] = "This is demo but new";

  printf("compare s1 & s2 (12): %d\n", strncmp(s1, s2, 12));
  printf("compare s1 & s3 (12): %d\n", strncmp(s1, s3, 12));
  printf("compare s3 & s2 (12): %d\n", strncmp(s3, s2, 12));
  printf("compare s3 & s2 (20): %d\n", strncmp(s3, s2, 20));

  return 0;
}

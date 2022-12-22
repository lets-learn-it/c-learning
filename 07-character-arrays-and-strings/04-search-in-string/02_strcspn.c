#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[] = "fcba73";
  char keys[] = "1234567890";

  int i;
  i = strcspn (str,keys);

  printf ("The first number in str is at position %d.\n",i+1);
  
  return 0;
}

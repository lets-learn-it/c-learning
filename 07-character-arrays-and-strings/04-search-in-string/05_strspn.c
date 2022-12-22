#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[] = "1245fcba";
  char keys[] = "1234567890";

  int i;
  i = strspn (str,keys);

  printf ("The first %d characters are numbers\n",i);
  
  return 0;
}

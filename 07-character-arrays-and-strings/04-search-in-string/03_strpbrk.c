#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[] = "This is a sample string";
  char key[] = "aeiou";

  char * pch;
  printf ("Vowels in '%s': ",str);

  pch = strpbrk (str, key);

  while (pch != NULL)
  {
    printf ("%c " , *pch);
    pch = strpbrk (pch+1,key);
  }

  printf ("\n");
  
  return 0;
}

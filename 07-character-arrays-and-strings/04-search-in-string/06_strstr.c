#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[] ="This is a simple string";
  char * pch;

  pch = strstr (str,"simple");

  if (pch != NULL)
    strncpy (pch,"sample",6);

  puts (str);
  
  return 0;
}

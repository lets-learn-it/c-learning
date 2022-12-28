#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i;

  for (i=0;i<argc;i++)
    fprintf(stdout, "%s\n", argv[i]);

  printf("---------------------\n");

  // As argv[argc] is null pointer
  for (i=0;argv[i]!=NULL;i++)
    fprintf(stdout, "%s\n", argv[i]);

  return 0;
}

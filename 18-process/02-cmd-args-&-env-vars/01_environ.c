#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  extern char **environ;

  int i;

  for (i=0;environ[i] != NULL;i++)
    fprintf(stdout, "%s\n", environ[i]);

  // add new environment at last
  environ[i] = "MyName=Parikshit";

  // add null at last position
  environ[++i] = NULL;

  for (i=0;environ[i] != NULL;i++)
    fprintf(stdout, "%s\n", environ[i]);
  return 0;
}

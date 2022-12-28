#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  fprintf(stdout, "hostname: %s\n", getenv("hostname"));

  putenv("hostname=blabla");

  fprintf(stdout, "hostname: %s\n", getenv("hostname"));

  // change existing env var

  fprintf(stdout, "PWD: %s\n", getenv("PWD"));

  putenv("PWD=blabla");

  fprintf(stdout, "PWD: %s\n", getenv("PWD"));
  
  return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  fprintf(stdout, "hostname: %s\n", getenv("hostname"));

  setenv("hostname", "blabla", 1);

  fprintf(stdout, "hostname: %s\n", getenv("hostname"));

  unsetenv("hostname");

  fprintf(stdout, "hostname: %s\n", getenv("hostname"));

  // change existing env var

  fprintf(stdout, "PWD: %s\n", getenv("PWD"));

  // rewrite = 0 (if exists do not set)
  setenv("PWD", "blabla", 0);

  fprintf(stdout, "PWD: %s\n", getenv("PWD"));

  // overwrite
  setenv("PWD", "blabla", 1);

  fprintf(stdout, "PWD: %s\n", getenv("PWD"));
  
  return 0;
}

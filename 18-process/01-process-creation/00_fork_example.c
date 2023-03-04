#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define info(...) fprintf(stdout, __VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char const *argv[]) {
  pid_t p = getpid();
  err("My Process Id: %d\n", p);

  /* create new process */
  pid_t child = fork();

  if (child == 0) {
    err("I am child!!! (%d)\n", getpid());
  } else {
    err("I am Parent!!! (%d)\n", getpid());
  }
  return 0;
}

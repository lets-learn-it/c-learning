#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define info(...) fprintf(stdout, __VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char const *argv[]) {
  pid_t p = getpid();
  err("My Process Id: %d\n", p);

  /* create new process */
  pid_t child = fork();

  if (child == 0) {
    err("I am child!!! (%d)\n", getpid());
    exit(100);
  } else {
    int rv = 0, exit_code = -1;
    pid_t c = wait(&rv);
    if (WIFEXITED(rv)) {
      exit_code = WEXITSTATUS(rv);
    }
    err("I am Parent!!! (%d). Child (%d) exited. Exit code: %d\n", getpid(), c, exit_code);
  }
  return 0;
}

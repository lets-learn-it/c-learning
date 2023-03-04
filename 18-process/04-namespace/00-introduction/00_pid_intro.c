#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/sched.h>

#define info(...) fprintf(stdout, __VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char const *argv[]) {
  pid_t p = getpid();
  err("My Process Id: %d\n", p);

  if (unshare(CLONE_NEWPID) == -1) {
    perror("unshare");
  }

  /* Create new process using fork as
   * new namespace will only affect the processes created after the unshare call
   */
  pid_t child = fork();
  if (child == 0) {
    /* This is child should have 0 pid */
    err("My Pid (child): %d\n", getpid());
  } else {
    err("My Pid (parent): %d\n", getpid());
  }

  return 0;
}

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/sched.h>

#define info(...) fprintf(stdout, __VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)

int main(int argc, char const *argv[]) {
  err("I ran by user with Id: %d\n", getuid());

  if (unshare(CLONE_NEWUSER) == -1) {
    perror("unshare");
  }

  err("I ran by user with Id: %d\n", getuid());
  
  return 0;
}

#define _POSIX_C_SOURCE 1   // https://stackoverflow.com/questions/54718687/how-do-i-use-sigaction-struct-sigaction-is-not-defined
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig) {
  const char msg[] = "No, I am not exiting.\n";
  write(0, msg, sizeof(msg));

  // Why not printf
  // signal handler and all functions called from signal handler should be async safe.
}

int main() {
  struct sigaction sa = {
    .sa_handler = sigint_handler,
    .sa_flags = 0,
    .sa_mask = 0,
  };

  if (sigaction(SIGINT, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }

  int x;

  while(1) { 
    printf("Enter: ");
    scanf("%d", &x);

    if (x == 100)
      break;
  }

  return 0;
}
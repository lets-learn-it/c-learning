#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_signal(int sig, siginfo_t *info, void *context) {
  printf("Received signal %d\n", sig);
  if (sig == SIGINT) {
    printf("SIGINT: ctrl+c\n");
  }
}

int main() {
  struct sigaction sa = {0};

  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = handle_signal;

  sigaction(SIGINT, &sa, NULL);

  sleep(100);
  return 0;
}

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void exit1(int sig) {
  printf("got signal: %d\n", sig);
  return;
}

int main() {
  signal(SIGINT, exit1);   // ctrl + c
  signal(SIGTERM, exit1);  // kill <pid>

  sleep(100);
  return 0;
}

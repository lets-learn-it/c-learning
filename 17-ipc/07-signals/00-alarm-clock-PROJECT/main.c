#define _POSIX_SOURCE  /* for sigset_t */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// handler
void handle_SIGALRM(int sig) {
  fprintf(stdout, "Alarm ringing....\n");
  system("mpg123 clock-sound-effect.mp3");
}

int main(int argc, char const *argv[]) {
  // suspend all signals. We have to wait for only SIGALRM
  sigset_t set;

  // select all signals
  sigfillset(&set);

  // remove SIGALRM from set
  sigdelset(&set, SIGALRM);

  // block all signals except SIGALRM
  sigprocmask(SIG_BLOCK, &set, NULL);

  // register handler with kernel
  signal(SIGALRM, handle_SIGALRM);

  // set alarm after 5 seconds
  alarm(5);

  // suspends the process until signal arrives
  pause();
  
  return 0;
}

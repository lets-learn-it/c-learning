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
  // register handler with kernel
  signal(SIGALRM, handle_SIGALRM);

  // set alarm after 5 seconds
  alarm(5);

  // suspends the process until signal arrives
  pause();

  return 0;
}

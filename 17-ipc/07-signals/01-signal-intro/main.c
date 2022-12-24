#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void handle_SIGUSR1(int signum) {
  char *s = "Work done.\n";

  // check for reentrant functions
  // & also https://man7.org/linux/man-pages/man7/signal-safety.7.html
  write(STDOUT_FILENO, s, strlen(s));
}

int do_work() {
  fprintf(stdout, "Working...\n");
  sleep(5);
  fprintf(stdout, "Work done. Sending signal to parent...\n");
  return getppid();
}

int main(int argc, char const *argv[]) {
  signal(SIGUSR1, handle_SIGUSR1);

  int pid = fork();

  if (pid == 0) {
    int ppid = do_work();

    // send signal to parent
    if (kill(ppid, SIGUSR1) == -1) {
      perror("kill");
    }

    fprintf(stdout, "Signal Sent. Exiting...\n");
    exit(0);
  } else {
    pause();
  }
  return 0;
}

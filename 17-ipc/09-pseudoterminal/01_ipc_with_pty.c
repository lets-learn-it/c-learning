#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define __USE_BSD
#include <termios.h>

int main() {
  int fdm, fds, rc;
  char input[150];

  // get a master pseudo-terminal handle
  fdm = posix_openpt(O_RDWR);
  if (fdm < 0) {
    perror("posix_openpt");
    return 1;
  }

  // Chown the slave to the calling user.
  rc = grantpt(fdm);
  if (rc != 0) {
    perror("grantpt");
    return 1;
  }

  // Release an internal lock so the slave can be opened.
  rc = unlockpt(fdm);
  if (rc != 0) {
    perror("unlockpt");
    return 1;
  }

  fds = open(ptsname(fdm), O_RDWR);

  char shell[] = "Input: ";

  if (fork()) {   // father
    // close child side of pty
    close(fds);
    while(1) {
      write(1, shell, sizeof(shell));
      rc = read(0, input, sizeof(input));
      if (rc > 0) {
        write(fdm, input, rc);

        rc = read(fdm, input, sizeof(input) - 1);
        if (rc > 0) {
          input[rc] = '\0';
          fprintf(stderr, "%s", input);
        } else {
          break;
        }
      } else {
        break;
      }
    }
  } else {        // child
    struct termios slave_orig_term_settings;
    struct termios new_term_settings;

    close(fdm);
    rc = tcgetattr(fds, &slave_orig_term_settings);

    new_term_settings = slave_orig_term_settings;
    cfmakeraw(&new_term_settings);
    tcsetattr(fds, TCSANOW, &new_term_settings);

    // close stds
    close(0); close(1); close(2);

    dup(fds); dup(fds); dup(fds);

    while(1) {
      rc = read(fds, input, sizeof(input) - 1);

      if (rc > 0) {
        input[rc-1] = '\0';
        printf("Child received: '%s'\n", input);
      } else {
        break;
      }
    }
  }
  return 0;
}

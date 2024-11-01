#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define __USE_BSD
#include <termios.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  int fdm, fds, rc;
  char input[150];

  if (argc <= 1) {
    fprintf(stderr, "Usage: %s program_name [parameters]\n", argv[0]);
    exit(1);
  }

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

  if (fork()) {   // parent
    fd_set fd_in;

    // close child side of pty
    close(fds);
    while(1) {
      FD_ZERO(&fd_in);
      FD_SET(0, &fd_in);
      FD_SET(fdm, &fd_in);

      rc = select(fdm+1, &fd_in, NULL, NULL, NULL);
      if (rc == -1) {
        perror("select");
        exit(1);
      }

      if (FD_ISSET(0, &fd_in)) {
        rc = read(0, input, sizeof(input));
        if (rc > 0) {
          write(fdm, input, rc);
        } else if (rc < 0) {
          perror("readp1");
          exit(1);
        }
      }

      if (FD_ISSET(fdm, &fd_in)) {
        rc = read(fdm, input, sizeof(input));
        if (rc > 0) {
          write(1, input, rc);
        } else if (rc < 0) {
          perror("readp2");
          exit(1);
        }
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

    close(fds);

    // Make the current process a new session leader
    setsid();

    // As the child is a session leader, set the controlling terminal to be the slave side of the PTY
    // (Mandatory for programs like the shell to make them manage correctly their outputs)
    ioctl(0, TIOCSCTTY, 1);

    char **child_av;
    int i;

    child_av = (char **) malloc(argc * sizeof(char *));

    for (i=1; i<argc; i++) {
      child_av[i-1] = strdup(argv[i]);
    }

    child_av[i-1] = NULL;
    rc = execvp(child_av[0], child_av);
  }
  return 0;
}

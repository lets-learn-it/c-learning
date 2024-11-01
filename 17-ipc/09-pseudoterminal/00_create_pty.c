#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main() {
  int fdm, rc;

  system("ls -l /dev/pts");

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

  system("ls -l /dev/pts");
  printf("The slave side is named: %s\n", ptsname(fdm));
  return 0;
}

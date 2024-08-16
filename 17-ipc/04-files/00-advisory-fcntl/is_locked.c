#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  struct flock fl = { 0 };

  int fd = open("../file.txt", O_WRONLY);
  fcntl(fd, F_GETLK, &fl);   /* F_GETLK, F_SETLK, F_SETLKW */

  if (fl.l_type == F_WRLCK) {
    printf("file is locked by process %d\n", fl.l_pid);
  } else {
    printf("file not locked.\n");
  }

  close(fd);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  struct flock fl = {
    .l_type = F_WRLCK,    /* F_RDLCK, F_WRLCK, F_UNLCK */
    .l_whence = SEEK_SET, /* SEEK_SET, SEEK_CUR, SEEK_END */
    .l_start = 0,         /* Offset from l_whence */
    .l_len = 0,           /* length, 0 mean whole file */
    // .l_pid             /* PID holding lock, F_RDLCK only. set bu kernel */
  };

  int fd = open("../file.txt", O_WRONLY);
  fcntl(fd, F_SETLKW, &fl);   /* F_GETLK, F_SETLK, F_SETLKW */

  sleep(10);

  fl.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &fl);
  close(fd);

  return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[]) {
  int fifofd;
  char *msg = "Hello, World";
  const char *FIFO = "/tmp/my_fifo";

  // unlink FIFO if exist
  // check https://man7.org/linux/man-pages/man2/unlink.2.html
  // fifo will be removed but processes which have the object open may continue to use it.
  if(unlink(FIFO) == -1 && errno == ENOENT) {
    fprintf(stderr, "Fifo doesn't exist. We dont care ¯\\_(ツ)_/¯");
  }

  if(mkfifo(FIFO, S_IRUSR | S_IWUSR) != 0) {
    perror("mkfifo");
    exit(1);
  }

  if((fifofd = open(FIFO, O_WRONLY)) == -1) {
    perror("open");
    exit(1);
  }

  write(fifofd, msg, strlen(msg) + 1);
  
  close(fifofd);
  return 0;
}

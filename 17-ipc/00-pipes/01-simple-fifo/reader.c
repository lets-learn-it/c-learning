#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 5

int main(int argc, char const *argv[]) {
  int fifofd, nbytes;
  char buffer[BUFFER_SIZE];
  const char *FIFO = "/tmp/my_fifo";

  if((fifofd = open(FIFO, O_RDONLY)) == -1) {
    perror("open");
    exit(1);
  }

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);

    if((nbytes = read(fifofd, &buffer, BUFFER_SIZE)) < 0) {
      perror("read");
      exit(0);
    } 

    if(nbytes == 0) {
      break;
    }

    fprintf(stdout, "received %d bytes: %s\n", nbytes, buffer);
  }
  
  
  close(fifofd);
  return 0;
}

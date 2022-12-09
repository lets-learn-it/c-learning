#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int main(int argc, char const *argv[]) {
  int fd[2], nbytes;
  pid_t child_pid;
  char *s = "Hello World";
  char buffer[BUFFER_SIZE];

  /*************************************
   * create pipe
   * fd[0] for reading
   * fd[1] for writing
   * returns 0 if successful else -1
   *************************************/
  pipe(fd);


  // create child process using fork
  if ((child_pid = fork()) == -1) {
    perror("fork");
    exit(1);
  }

  if (child_pid == 0) { // if child
    // close reading end
    close(fd[0]);

    // write to pipe
    write(fd[1], s, strlen(s) + 1);

    // close writing end & close child
    close(fd[1]);
    exit(0);
  } else {  // parent
    // close writing end
    close(fd[1]);

    while(1) {
      nbytes = read(fd[0], buffer, BUFFER_SIZE);

      if (nbytes == 0) {
        fprintf(stdout, "EOF");
        break;
      }

      if (nbytes < 0) {
        perror("read");
        exit(1);
      }

      fprintf(stdout, "received %d bytes. %s\n", nbytes, buffer);
    }
    
    // close reading end
    close(fd[0]);
  }
  
  return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/************************************************************************************************
 * parent will send integer over pipe to child and child has to compute square of it and print
 * we will fork child process from parent then
 * close stdin and duplicate fd[0] (reading end) as stdin in child
 * & close stdout and duplicate fd[1] (writing end) as stdout in parent
 * so that whatever parent write to stdout, will be available in stdin of child
 *************************************************************************************************/

#define N 10

int main(int argc, char const *argv[]) {
  int fd[2], nbytes;
  pid_t child_pid;
  int arrn = 10;
  int arr[N] = {1,2,3,4,5,6,7,8,9,10};
  
  pipe(fd);

  // create child process using fork
  if ((child_pid = fork()) == -1) {
    perror("fork");
    exit(1);
  }

  if (child_pid == 0) { // if child
    close(fd[1]);

    // close stdin and duplicate reading end of pipe
    dup2(fd[0], 0);

    int number = 0, n = 0;

    scanf("%d", &n);

    while(n > 0) {
      scanf("%d", &number);

      fprintf(stdout, "received %d. sqaure(%d) = %d\n", number, number, number*number);
      n--;
    }

    exit(0);
  } else {  // in parent
    close(fd[0]);

    // close stdout & duplicate writing end of pipe
    dup2(fd[1], 1);

    fprintf(stdout, "%d\n", N);

    for(int i=0;i<N;i++)
      fprintf(stdout, "%d\n", arr[i]);
    
  }
  return 0;
}

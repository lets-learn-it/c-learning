#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // variable will be different in 2 processes
  int *x;

  // if we dont allocate this dynamically
  // both parent & child will have same virtual address
  x = malloc(sizeof(x));

  *x = 2;

  // This pid will be 0 for child 
  // and will be actuall child pid in parent
  int pid = fork();

  if (pid == 0) {
    fprintf(stdout, "I am child.Incrementing...\n");
    (*x)++;
    
  } else {
    fprintf(stdout, "I must be parent. decrementing...\n");
    (*x)--;
  }

  // x will be pointer but we want address we allocated using malloc
  fprintf(stdout, "Value of X: %d & Address: %p\n", *x, &(*x));

  wait(pid);
  
  return 0;
}

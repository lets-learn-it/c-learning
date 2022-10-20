#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // below code will use clone system call to create threads 
  // and each thread will run whole block
  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    pid_t pid = gettid();

    printf("OMP id: %d & PID/TID of Thread: %d\n", id, pid);
  }

  return 0;
}
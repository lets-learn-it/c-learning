#define _GNU_SOURCE
#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // 0 no nested, 1 nested
  omp_set_nested(1);

  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    pid_t pid = gettid();

    printf("OMP id: %d & PID/TID of Thread: %d\n", id, pid);

    #pragma omp parallel
    {
      int id = omp_get_thread_num();
      pid_t pid = gettid();

      printf("  OMP id: %d & PID/TID of Thread: %d\n", id, pid);
    }
  }

  return 0;
}
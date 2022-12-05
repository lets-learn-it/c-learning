#define _GNU_SOURCE
#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**********************************************
 * 3 ways to set number of threads
 * set env variable OMP_NUM_THREADS
 * call omp_set_num_threads(threads) routine
 * add num_threads(5) infront of parallel
 **********************************************/

int main() {
  int threads = omp_get_num_threads();
  printf("Number of threads set from Env variable: %d\n", threads);

  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    pid_t pid = gettid();

    printf("OMP id: %d & PID/TID of Thread: %d\n", id, pid);
  }


  omp_set_num_threads(3);
  threads = omp_get_num_threads();
  printf("Number of threads set from routine call: %d\n", threads);

  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    pid_t pid = gettid();

    printf("OMP id: %d & PID/TID of Thread: %d\n", id, pid);
  }

  printf("Number of threads UNKNOWN\n");
  
  #pragma omp parallel num_threads(5)
  {
    int id = omp_get_thread_num();
    pid_t pid = gettid();

    printf("OMP id: %d & PID/TID of Thread: %d\n", id, pid);
  }

  return 0;
}
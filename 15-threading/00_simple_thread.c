#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* routine() {
  fprintf(stdout, "This is thread...\n");
}

/* 
 * Compile: gcc -pthread 00_simple_thread.c
 */

int main(int argc, char const *argv[]) {
  pthread_t t1, t2;

  if(pthread_create(&t1, NULL, &routine, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  if(pthread_create(&t2, NULL, &routine, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  fprintf(stdout, "In Main...\n");

  // wait for thread else main thread will return
  if(pthread_join(t1, NULL) != 0) {
    fprintf(stderr, "ERROR [pthread_join]: Something gone wrong...\n");
    return 1;
  }

  if(pthread_join(t2, NULL) != 0) {
    fprintf(stderr, "ERROR [pthread_join]: Something gone wrong...\n");
    return 1;
  }

  return 0;
}

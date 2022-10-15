#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void* routine1() {
  fprintf(stdout, "This is thread1...\n");

  // Thread routine return 
  // thread will die/exit
}

void* routine2() {
  fprintf(stdout, "This is thread2...\n");

  // thread will die/exit
  pthread_exit(0);
  
  fprintf(stdout, "This line will not execute...\n");
}

void* routine3() {
  fprintf(stdout, "This is thread3...\n");

  sleep(1);

  // main thread will kill t3

  fprintf(stdout, "Am I still alive???");
}

/* 
 * Thread can die/exit by one of below condition
 * - __start_routine returns
 * - thread calls pthread_exit
 * - some other thread cancels current thread
 */

int main(int argc, char const *argv[]) {
  pthread_t t1, t2, t3;

  if(pthread_create(&t1, NULL, &routine1, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  if(pthread_create(&t2, NULL, &routine2, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  if(pthread_create(&t3, NULL, &routine3, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  fprintf(stdout, "In Main...\n");

  // both main & t3 thread sleep for 1 sec
  // if t3 is lucky, it will execute completely
  // else main will cancel it.
  sleep(1);
  pthread_cancel(t3);

  // We can use pthread_kill to send signal to thread
  // instead of pthread_cancel, we can use pthread_kill(t3, SIGKILL)
  // pthread_kill(t3, SIGKILL);

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

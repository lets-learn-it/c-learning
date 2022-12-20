#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void * thread_fn_callback(void *arg) {
  fprintf(stdout, "This is thread...\n");

  int th_id = *(int *) arg;

  free(arg);

  int *result = calloc(1, sizeof(int));
  int rc = 0;

  while(rc != th_id) {
    *result += th_id;
    sleep(1);
    rc++;
  }
}

void thread_create(pthread_t *pthread_handle, int num) {
  // define properties of new thread
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  // we will create detached thread (by default it creates JOINABLE)
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  int *_num = calloc(1, sizeof(int));
  *_num = num;
  pthread_create(pthread_handle, &attr, thread_fn_callback, (void *) _num);
}

int main(int argc, char const *argv[]) {
  pthread_t t1, t2;
  void *thread_result;

  thread_create(&t1, 2);
  thread_create(&t2, 5);

  // you can't join detached thread
  if(pthread_join(t2, &thread_result) != 0) {
    fprintf(stderr, "ERROR [pthread_join]: Something gone wrong...\n");
    // should return but not in this example
    // return 1;
  }

  // sleep so detached threads can complete
  sleep(5);

  return 0;
}

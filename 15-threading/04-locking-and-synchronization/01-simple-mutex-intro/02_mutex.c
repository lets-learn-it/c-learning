#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int total = 0, count = 1000000;
pthread_mutex_t mutex;

void* routine() {
  for (int i = 0; i < count; i++) {
    pthread_mutex_lock(&mutex);
    total++;
    pthread_mutex_unlock(&mutex);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t t1, t2;

  pthread_mutex_init(&mutex, NULL);

  if(pthread_create(&t1, NULL, &routine, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  if(pthread_create(&t2, NULL, &routine, NULL) != 0) {
    fprintf(stderr, "ERROR: Something gone wrong...\n");
    return 1;
  }

  // wait for thread else main thread will return
  if(pthread_join(t1, NULL) != 0) {
    fprintf(stderr, "ERROR [pthread_join]: Something gone wrong...\n");
    return 1;
  }

  if(pthread_join(t2, NULL) != 0) {
    fprintf(stderr, "ERROR [pthread_join]: Something gone wrong...\n");
    return 1;
  }

  pthread_mutex_destroy(&mutex);

  fprintf(stdout, "Total (should be %d): %d", 2*count, total);

  return 0;
}

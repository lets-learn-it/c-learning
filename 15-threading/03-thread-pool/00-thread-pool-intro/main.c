#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 4

typedef struct task_node_ {
  int id;
  int a, b;
  int result; // number of primes in a to b
} task_node_t;

task_node_t taskq[256];
int taskCount = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

int isPrime(int x) {
  int flag = 0;
  if (x == 1) return 0;
  for (int i=1;i<=x;i++) {
    if (x%i == 0) flag ++;
    if (flag > 2) return 0;
  }
  return 1;
}

void task_func(task_node_t *t) {
  int result = 0;
  for (int i=t->a; i<=t->b;i++) {
    if (isPrime(i)) result++;
  }
  t->result = result;
}

void* startThread(void *args) {
  while(1) {
    task_node_t task;

    // lock
    pthread_mutex_lock(&mutex);

    while (taskCount == 0)
      pthread_cond_wait(&cond, &mutex);

    task = taskq[0];

    // move all tasks to left
    for (int i=0;i<taskCount - 1;i++) {
      taskq[i] = taskq[i+1];
    }

    taskCount--;
    

    // unlock
    pthread_mutex_unlock(&mutex);

    task_func(&task);
    fprintf(stdout, "%d. Primes between %d and %d = %d\n", task.id, task.a, task.b, task.result);
  }
}

void submitTask(task_node_t task) {
  fprintf(stdout, "%d. submitting %d and %d\n", task.id, task.a, task.b);
  pthread_mutex_lock(&mutex);
  taskq[taskCount] = task;
  taskCount ++;
  pthread_mutex_unlock(&mutex);
  pthread_cond_signal(&cond);
}

int main(int argc, char const *argv[]) {
  pthread_t threads[THREAD_NUM];
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  for (int i=0;i<THREAD_NUM;i++) {
    if (pthread_create(&threads[i], NULL, &startThread, NULL) != 0) {
      perror("pthread_create");
    }
  }

  srand(time(NULL));
  for (int i=0;i<10;i++) {
    task_node_t t = {
      .id = i,
      .a = rand() % 100,
      .b = rand() % 1000000,
      .result = 0
    };
    submitTask(t);
  }

  for (int i = 0;i<THREAD_NUM;i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("pthread_join");
    }
  }
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}

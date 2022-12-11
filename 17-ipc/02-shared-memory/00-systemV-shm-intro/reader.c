#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  void *shared_memory;
  char buffer[100];
  int shmid;

  if((shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT)) == -1) {
    perror("shmget");
    exit(1);
  }

  shared_memory = shmat(shmid, NULL, 0);

  if(*(int *)shared_memory == -1) {
    perror("shmat");
    exit(1);
  }

  fprintf(stdout, "Shared memory attached at %p\n", shared_memory);

  strcpy(buffer, shared_memory);

  fprintf(stdout, "Data from shared memory: %s", buffer);
  return 0;
}

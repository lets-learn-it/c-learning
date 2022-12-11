#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/ipc.h>

#define DETACH 0

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

  fprintf(stdout, "Data from shared memory: %s\n", buffer);

  // detaching will not remove sharable memory
  // it will only detach that memory from calling process
  if(DETACH && shmdt(shared_memory) == 0) {
    fprintf(stdout, "detached successfully...\n");
  }

  // remove shared memory
  if(shmctl(shmid, IPC_RMID, NULL) == 0) {
    fprintf(stdout, "Destroyed shared memory...");
  }
  return 0;
}

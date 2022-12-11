#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  const char *data = "This is demo data. Will be written to shared memory";
  void *shared_memory;
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
  
  strcpy(shared_memory, data);
  return 0;
}

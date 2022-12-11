#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>   /* for O_* constants*/

#define SHARED_SIZE 1024

int main(int argc, char const *argv[]) {
  void *shared_memory;
  char buffer[100];
  int shmfd;

  if((shmfd = shm_open("/shm_demo", O_CREAT | O_RDWR, S_IRUSR)) == -1) {
    perror("shm_open");
    exit(1);
  }

  if(ftruncate(shmfd, SHARED_SIZE) == -1) {
    perror("ftruncate");
    exit(1);
  }

  // map file descriptor so file operations arent needed
  shared_memory = mmap(NULL, SHARED_SIZE, PROT_READ, MAP_SHARED, shmfd, 0);

  fprintf(stdout, "Shared memory attached at %p\n", shared_memory);

  strcpy(buffer, shared_memory);

  fprintf(stdout, "Data from shared memory: %s", buffer);

  munmap(shared_memory, SHARED_SIZE);
  close(shmfd);

  // unlink shared memory 
  // shm_unlink("/shm_demo")
  return 0;
}

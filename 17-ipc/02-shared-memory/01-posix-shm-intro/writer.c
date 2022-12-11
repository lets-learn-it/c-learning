#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>   /* for O_* constants*/

#define SHARED_SIZE 1024

int main(int argc, char const *argv[]) {
  const char *data = "This is demo data. Will be written to shared memory";
  void *shared_memory;
  int shmfd;

  // shared memory should be O_RDWR else mmap will fail with permission denied
  if((shmfd = shm_open("/shm_demo", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR)) == -1) {
    perror("shm_open");
    exit(1);
  }

  if(ftruncate(shmfd, SHARED_SIZE) == -1) {
    perror("ftruncate");
    exit(1);
  }

  // map file descriptor so file operations arent needed
  if((shared_memory = mmap(NULL, SHARED_SIZE, PROT_WRITE, MAP_SHARED, shmfd, 0)) == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  fprintf(stdout, "Shared memory attached at %p\n", shared_memory);

  strcpy(shared_memory, data);

  munmap(shared_memory, SHARED_SIZE);
  close(shmfd);

  // unlink shared memory 
  // shm_unlink("/shm_demo")
  return 0;
}

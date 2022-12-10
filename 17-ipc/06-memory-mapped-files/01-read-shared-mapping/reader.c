#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  const char *name = "file.txt";

  int fd;
  char *mmap_addr;
  struct stat file_info;
  
  if((fd = open(name, O_RDONLY)) == -1) {
    perror("open");
    exit(1);
  }

  if(fstat(fd, &file_info) == -1) {
    perror("fstat");
    close(fd);
    exit(1);
  }

  if((mmap_addr = mmap(NULL, file_info.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED) {
    perror("mmap");
    close(fd);
    exit(0);
  }

  int i = 0;

  while(i < file_info.st_size || (fstat(fd, &file_info) != -1 && i < file_info.st_size)) {
    // using stderr for not buffering
    fprintf(stderr, "%c", mmap_addr[i]);
    if (mmap_addr[i] == '\0') { 
      fprintf(stderr, "EOF");
      break;
    }
    i++;
    sleep(1);
  }

  munmap(mmap_addr, file_info.st_size);
  close(fd);
  return 0;
}

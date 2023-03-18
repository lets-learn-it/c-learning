#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  const char *filename = argv[1];

  if(filename == NULL) {
    fprintf(stderr, "Provide filename...");
  }

  int fd = open(filename, O_RDONLY);
  
  printf("%s", filename);
  return 0;
}

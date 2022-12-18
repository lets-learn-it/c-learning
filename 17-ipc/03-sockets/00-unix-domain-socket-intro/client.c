#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/mysocket"
#define BUFFER_SIZE 128

int main(int argc, char const *argv[]) {
  struct sockaddr_un addr;
  int i = 0;
  int ret, datasock, result, data;
  char buffer[BUFFER_SIZE];

  if (argc < 2) {
    fprintf(stderr, "Pass integer");
    exit(EXIT_FAILURE);
  }

  i = atoi(argv[1]);

  if ((datasock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&addr, 0, sizeof(struct sockaddr_un));

  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path));

  if (connect(datasock, (const struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }
  
  do {
    if (write(datasock, &i, sizeof(int)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }
    
  } while(i--);

  memset(buffer, 0, BUFFER_SIZE);
  if (read(datasock, buffer, BUFFER_SIZE) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  printf("%s", buffer);
  close(datasock);
  return 0;
}

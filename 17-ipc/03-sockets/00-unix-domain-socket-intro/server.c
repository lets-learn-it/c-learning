#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/mysocket"
#define BUFFER_SIZE 128

int main(int argc, char const *argv[]) {
  struct sockaddr_un name;

  int ret, connsock, datasock, result, data;
  char buffer[BUFFER_SIZE];

  // remove socket if it is exists with same name
  unlink(SOCKET_NAME);

  // SOCK_DGRAM for datagram based communication
  if ((connsock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&name, 0, sizeof(struct sockaddr_un));

  name.sun_family = AF_UNIX;
  strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

  if (bind(connsock, (const struct sockaddr *) &name, sizeof(struct sockaddr_un)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // backlog size is 20
  if (listen(connsock, 20) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  for(;;) {
    if ((datasock = accept(connsock, NULL, NULL)) == -1) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    result = 0;

    for(;;) {
      memset(buffer, 0, BUFFER_SIZE);

      // make sure you read only sizeof int 
      // because if you read all available data, you will loose some data
      if (read(datasock, buffer, sizeof(int)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
      }

      memcpy(&data, buffer, sizeof(int));
      // fprintf(stdout, "%d\n", data);
      if(data == 0) break;
      result += data;
    }


    // send result back
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "Result = %d", result);

    if (write(datasock, buffer, BUFFER_SIZE) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    close(datasock);
  }

  close(connsock);

  unlink(SOCKET_NAME);
  return 0;
}

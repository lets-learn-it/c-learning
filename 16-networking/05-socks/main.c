#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>



void printHex(char *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%02X ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int sockfd, connfd;
  struct sockaddr_in serv_addr;
  int addrlen = sizeof serv_addr;
  char inbuffer[16] = {0};
  char outBuffer[16] = {0};

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8081);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // https://stackoverflow.com/questions/2208581/socket-listen-doesnt-unbind-in-c-under-linux
  int opt = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *) &opt, sizeof(opt));

  if(bind(sockfd, (struct sockaddr *) &serv_addr, addrlen) < 0) {
    perror("bind failed...");
    exit(1);
  } 

  if(listen(sockfd, 3) < 0) {
    perror("Listen failed ...");
    exit(1);
  }

  if((connfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen)) < 0) {
    perror("accept error...");
    exit(1);
  }


  while(1) {
    memset(inbuffer, 0, 16);
    memset(outBuffer, 0, 16);

    // read returns 0 if connection closed normally
    // and -1 if error
    if(read(connfd, inbuffer, 16) <= 0) {
      fprintf(stderr, "%s (code: %d)\n", strerror(errno), errno);
      fprintf(stderr, "Host disconnected\n");
      close(connfd);
      exit(0);
    }
    printHex(inbuffer, 16);
    unsigned char octet[2] = {0x05, 0x00};
    printHex(octet, 2);
    write(connfd, &octet, 2);
  }

  return 0;
}

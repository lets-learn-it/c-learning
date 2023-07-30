#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "socks5.h"

void printHex(char *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%02X ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int mastersockfd;
  int activeconnections = 0;
  
  struct sockaddr_in serv_addr, client_addr;
  int addrlen = sizeof serv_addr;

  if((mastersockfd = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(1080);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // https://stackoverflow.com/questions/2208581/socket-listen-doesnt-unbind-in-c-under-linux
  int opt = 1;
  setsockopt(mastersockfd, SOL_SOCKET, SO_REUSEADDR, (void *) &opt, sizeof(opt));

  if(bind(mastersockfd, (struct sockaddr *) &serv_addr, addrlen) < 0) {
    perror("bind failed...");
    exit(1);
  } 

  if(listen(mastersockfd, 3) < 0) {
    perror("Listen failed ...");
    exit(1);
  }


  while(1) {
    int newFd;
    pthread_t t1;

    if((newFd = accept(mastersockfd, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen)) < 0) {
      perror("accept error...");
      exit(1);
    }

    fprintf(stdout, "New connection %d from %s\n", newFd, inet_ntoa(client_addr.sin_addr));
    
    pthread_create(&t1, NULL, &handle_connection, &newFd);
    // handle_connection(newFd);
  }

  return 0;
}
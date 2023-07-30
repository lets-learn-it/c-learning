#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include "socks5.h"

// #define __USE_XOPEN2K

void* handle_connection(void* _fd) {
  int fd = *(int *)_fd;
  printf("handle_connection: %d\n", fd);

  uint8_t version, nmethods, method, chosen = 0x00, cmd, rsv = 0x00, atype;
  unsigned short int port;
  struct in_addr *taddr;

  if (recv(fd, &version, sizeof(version), MSG_WAITALL) != 1) {
    perror("recv");
  }

  recv(fd, &nmethods, sizeof(nmethods), MSG_WAITALL);

  printf("(fd: %d): Version: %d, Nmethods: %d\n", fd, version, nmethods);

  for (uint8_t i=0;i<nmethods;i++) {
    recv(fd, &method, sizeof(nmethods), MSG_WAITALL);
    printf("Method: %d\n", method);
  }

  send(fd, &version, sizeof(version), MSG_MORE);
  send(fd, &chosen, sizeof(chosen), MSG_CONFIRM);

  recv(fd, &version, sizeof(version), MSG_WAITALL);
  recv(fd, &cmd, sizeof(cmd), MSG_WAITALL);
  recv(fd, &rsv, sizeof(rsv), MSG_WAITALL);
  recv(fd, &atype, sizeof(atype), MSG_WAITALL);

  printf("(fd: %d): Version: %d, cmd: %d, rsv: %d, atype: %d\n", fd, version, cmd, rsv, atype);
  char hostname[255];
  uint8_t len;
  if (atype == DOMAINNAME) {
    
    recv(fd, &len, sizeof(len), MSG_WAITALL);
    recv(fd, &hostname, len, MSG_WAITALL);
    hostname[len] = '\0';
    printf("Target domain: %s\n", hostname);
    resolve(hostname, &taddr);
  }

  recv(fd, &port, sizeof(port), MSG_WAITALL);
  printf("port: %d\n", ntohs(port));
  int tfd = create_tfd(port, *taddr);
  printf("fd: %d\n", tfd);

  send(fd, &version, sizeof(version), MSG_MORE);
  send(fd, &rsv, sizeof(rsv), MSG_MORE);
  send(fd, &rsv, sizeof(rsv), MSG_MORE);
  send(fd, &atype, sizeof(atype), MSG_MORE);
  send(fd, &len, 1, MSG_MORE);
  send(fd, hostname, len, MSG_MORE);
  // send(fd, &taddr, sizeof(taddr), MSG_MORE);
  // uint8_t p[] ={0x01, 0xbb};
  send(fd, &port, 2, MSG_CONFIRM);

  printf("fd: %d\n", tfd);

  pipe_data(fd, tfd);
}

void pipe_data(int sfd, int tfd) {
  unsigned char buffer[1024];

  int nbytes;
  int max_fd = sfd > tfd ? sfd : tfd;
  fd_set read_fds;
  
  while(1) {
    FD_ZERO(&read_fds);
    FD_SET(sfd, &read_fds);
    FD_SET(tfd, &read_fds);

    int ready = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
    if (ready < 0) {
      continue;
    }

    if (FD_ISSET(sfd, &read_fds)) {
      nbytes = read(sfd, buffer, 1024);
      write(tfd, buffer, nbytes);
    }
    
    if (FD_ISSET(tfd, &read_fds)) {
      nbytes = read(tfd, buffer, 1024);
      write(sfd, buffer, nbytes);
    }
  } 
}

int create_tfd(int port, struct in_addr addr) {
  int tfd;
  struct sockaddr_in serv_addr;
  if((tfd = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
    perror("error while creating socket...");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = port;
  serv_addr.sin_addr = addr;

  if(connect(tfd, (struct sockaddr *) &serv_addr, sizeof serv_addr) < 0) {
    perror("connect error...");
    exit(1);
  }

  return tfd;
}

int resolve(const char *hostname, struct in_addr **addr) {
  struct hostent *abv;
  abv = gethostbyname("www.baeldung.com");

  struct in_addr **addr_list = (struct in_addr **)abv->h_addr_list;
  for (int i=0;addr_list[i] != NULL; i++) {
    *addr = addr_list[i];
    break;
  }
  
  return 1;
}
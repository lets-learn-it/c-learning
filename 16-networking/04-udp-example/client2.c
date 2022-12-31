#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUFLEN 1024
#define PORT 8888
#define SERVER "127.0.0.1"

int main(int argc, char const *argv[]) {
  int readBytes, wroteBytes;
  int udp_sock;
  struct sockaddr_in dest_addr;
  struct msghdr desthdr;
  char buffer[BUFLEN];

  if ((udp_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&dest_addr, 0, sizeof(struct sockaddr_in));
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = htons(8888);
  
  if (inet_aton(SERVER, &dest_addr.sin_addr) == 0) {
    fprintf(stderr, "inet_aton failed...");
    return EXIT_FAILURE;
  }

  unsigned int addr_len = sizeof(dest_addr);

  strcpy(buffer, "Hi There. Whats up!!!");

  // prepare iovec
  struct iovec io;
  io.iov_base = &buffer;
  io.iov_len = strlen(buffer);

  // prepare msghdr
  desthdr.msg_iov = &io;
  desthdr.msg_iovlen = 1;
  desthdr.msg_name = &dest_addr;
  desthdr.msg_namelen = addr_len;

  if ((wroteBytes = sendmsg(udp_sock, &desthdr, 0)) == -1) {
    perror("sendto");
    return EXIT_FAILURE;
  }

  // change iovec buffer length
  io.iov_len = BUFLEN;

  readBytes = recvmsg(udp_sock, &desthdr, 0);

  fprintf(stdout, "Buffer: %s\n", buffer);
  return 0;
}
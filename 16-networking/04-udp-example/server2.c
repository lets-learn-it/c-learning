#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUFLEN 1024
#define PORT 8888

int main(int argc, char const *argv[]) {
  int readBytes, wroteBytes;
  int udp_sock;
  struct sockaddr_in my_addr, other_addr;
  struct sockaddr_in *point;
  char buffer[BUFLEN];
  struct msghdr otherhdr;

  memset(&otherhdr, 0, sizeof(struct msghdr));

  if ((udp_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&my_addr, 0, sizeof(struct sockaddr_in));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(PORT);
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  struct iovec io = {buffer, BUFLEN};
  other_addr.sin_family = AF_INET;
  otherhdr.msg_name = &other_addr;
  otherhdr.msg_namelen = sizeof(other_addr);
  otherhdr.msg_iov = &io;
  otherhdr.msg_iovlen = 1;

  if (bind(udp_sock, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  } 

  unsigned int addr_len = sizeof(other_addr);

  while (1) {
    memset(buffer, 0, BUFLEN);
    
    if ((readBytes = recvmsg(udp_sock, &otherhdr, 0) == -1)) {
      perror("recvmsg");
      return EXIT_FAILURE;
    }

    point = (struct sockaddr_in*) otherhdr.msg_name;
    fprintf(stdout, "Packet received from: %s from port %d\n", inet_ntoa(point->sin_addr), ntohs(point->sin_family));
    fprintf(stdout, "Buffer: %s\n", buffer);

    memset(buffer, 0, BUFLEN);
    strcpy(buffer, "Thanks for contacting!!!!");

    // change iovec
    io.iov_len = strlen(buffer);
    io.iov_base = &buffer;

    // reply back
    if ((wroteBytes = sendmsg(udp_sock, &otherhdr, 0)) == -1) {
      perror("sendmsg");
      return EXIT_FAILURE;
    }
  }

  return 0;
}

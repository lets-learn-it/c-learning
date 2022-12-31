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
  char buffer[BUFLEN];

  if ((udp_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&my_addr, 0, sizeof(struct sockaddr_in));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(PORT);
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(udp_sock, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  } 

  unsigned int addr_len = sizeof(other_addr);

  while (1) {
    if ((readBytes = recvfrom(udp_sock, buffer, BUFLEN, 0, (struct sockaddr *) &other_addr, &addr_len)) == -1) {
      perror("recvfrom");
      return EXIT_FAILURE;
    }

    fprintf(stdout, "Packet received from: %s from port %d\n", inet_ntoa(other_addr.sin_addr), ntohs(other_addr.sin_port));
    fprintf(stdout, "Buffer: %s\n", buffer);

    strcpy(buffer, "Thanks for contacting!!!");
    // reply back
    if ((wroteBytes = sendto(udp_sock, buffer, strlen(buffer), 0, (struct sockaddr *) &other_addr, addr_len)) == -1) {
      perror("sendto");
      return EXIT_FAILURE;
    }
  }

  return 0;
}

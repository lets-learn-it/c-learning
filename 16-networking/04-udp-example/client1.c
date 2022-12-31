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

  if ((wroteBytes = sendto(udp_sock, buffer, strlen(buffer), 0, (struct sockaddr *) &dest_addr, addr_len)) == -1) {
    perror("sendto");
    return EXIT_FAILURE;
  }

  readBytes = recvfrom(udp_sock, buffer, BUFLEN, 0, (struct sockaddr *)&dest_addr, &addr_len);

  fprintf(stdout, "Buffer: %s\n", buffer);
  return 0;
}
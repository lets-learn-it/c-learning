#define __USE_GNU
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>



int main(int argc, char const *argv[]) {
  struct hostent *abv;
  abv = gethostbyname("www.googletagmanager.com");

  struct in_addr **addr_list = (struct in_addr **)abv->h_addr_list;
  for (int i=0;addr_list[i] != NULL; i++) {
    printf("%s\n", inet_ntoa(*addr_list[i]));
  }
  return 0;
}

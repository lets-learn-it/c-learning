#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>

int main(int argc, char const *argv[]) {
  const int ap_size = 100;
  char host[BUFSIZ], ap[ap_size];

  if(gethostname(host, BUFSIZ) == -1) {
    fprintf(stderr, "Unable to obtain host name\n");
    exit(1);
  }

  fprintf(stdout, "host name: %s\n", host);

  // get all interfaces
  struct ifaddrs *ifaddr;

  if(getifaddrs(&ifaddr) == -1) {
    fprintf(stderr, "Error occured!!!");
    exit(1);
  }

  for (struct ifaddrs *ifa = ifaddr; ifa != NULL;
                    ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL)
      continue;

    // only check IPv4 & IPv6 families
    if (ifa->ifa_addr->sa_family == AF_INET || ifa->ifa_addr->sa_family == AF_INET6) {
      getnameinfo(ifa->ifa_addr, 
                  ifa->ifa_addr->sa_family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
                  ap,
                  ap_size,
                  0,
                  0,
                  NI_NUMERICHOST);

      fprintf(stdout, "%-18s%-8s%s\n", ifa->ifa_name, ifa->ifa_addr->sa_family == AF_INET ? "IPv4" : "IPv6", ap);
    }
  }
  
  freeifaddrs(ifaddr);
  return 0;
}

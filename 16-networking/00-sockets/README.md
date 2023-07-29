# Sockets

## Address Structures

### IPv4

```c
struct in_addr {
  in_addr_t s_addr;    /* 32 bit IPv4 Address */
};                     /* network byte ordered */

struct sockaddr_in {
  uint8_t        sin_len;    /* length of structure (16) (not used in linux) */
  sa_family_t    sin_family; /* AF_INET */
  in_port_t      sin_port;   /* 16 bit TCP/UDP port (network byte ordered) */
  struct in_addr sin_addr;   /* 32 bit IPv4 addr. (network byte ordered) */
  char           sin_zero[8] /* unused */
};
```

### IPv6

```c



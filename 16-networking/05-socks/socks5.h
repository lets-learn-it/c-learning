
#ifndef __SOCKS5__
#define __SOCKS5__

enum socks_method {
  NOAUTH   = 0x00,   /* No Authentication Required */
  GSSAPI   = 0x01,   /* GSSAPI */
  UERSPASS = 0x02,   /* Username/Password */
  NOMETHOD = 0xff    /* No Acceptable Method */
};

enum socks_command {
  CONNECT       = 0x01,
  BIND          = 0x02,
  UDP_ASSOCIATE = 0x03
};

enum socks_atype {
  IPV4       = 0x01,
  DOMAINNAME = 0x03,
  IPV6       = 0x04
};

void* handle_connection(void* fd);
int resolve(const char *hostname, struct in_addr **addr) ;
void pipe_data(int sfd, int tfd);
int create_tfd(int port, struct in_addr addr);

#endif
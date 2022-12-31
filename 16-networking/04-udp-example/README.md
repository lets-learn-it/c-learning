# UDP

- User datagram protocol (UDP) is connectionless protocol.

```c
udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
```

- Datagrams can be sent immediately using `sendto` & `sendmsg` with valid destination address as an argument.
- When connect is called on socket, the default destination address is set & datagram can now be sent using `send` or `write` without specifying destination address. Still `sendto` and `sendmsg` can be used for other destination addresses.
- while receiving `recvfrom` and `recvmsg` can be used.
- While using `sendmsg` and `recvmsg`, need to specify addresses using `struct msghdr`
```c
/* Structure describing messages sent by
   `sendmsg' and received by `recvmsg'.  */
struct msghdr
{
  void *msg_name;		/* Address to send to/receive from.  */
  socklen_t msg_namelen;	/* Length of address data.  */

  struct iovec *msg_iov;	/* Vector of data to send/receive into.  */
  size_t msg_iovlen;		/* Number of elements in the vector.  */

  void *msg_control;		/* Ancillary data (eg BSD filedesc passing). */
  size_t msg_controllen;	/* Ancillary data buffer length.
          !! The type should be socklen_t but the
          definition of the kernel is incompatible
          with this.  */

  int msg_flags;		/* Flags on received message.  */
};

struct iovec {       /* Scatter/gather array items */
  void  *iov_base;   /* Starting address */
  size_t iov_len;    /* Number of bytes to transfer */
};
```
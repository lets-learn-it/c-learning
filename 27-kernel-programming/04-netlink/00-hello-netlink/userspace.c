#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>
#include <memory.h>
#include <stdint.h>
#include <pthread.h>
#include <linux/version.h>

#define MAX_PAYLOAD 256
#define NETLINK_TEST_PROTOCOL 31
#define NLMSG_GREET 1

int send_netlink_msg_to_kernel(int sock_fd, char *msg, uint32_t msg_size, int nlmsg_type, uint16_t flags) {
  struct sockaddr_nl dest_addr; // nl mean netlink
  memset(&dest_addr, 0, sizeof(dest_addr));
  dest_addr.nl_family = AF_NETLINK;
  dest_addr.nl_pid = 0; // kernel

  struct nlmsghdr *nlh = (struct nlmsghdr *) calloc(1, NLMSG_HDRLEN + NLMSG_SPACE(msg_size));

  nlh->nlmsg_len = NLMSG_HDRLEN + NLMSG_SPACE(msg_size);
  nlh->nlmsg_pid = getpid();
  nlh->nlmsg_flags = flags;
  nlh->nlmsg_type = nlmsg_type;
  nlh->nlmsg_seq = 0;

  // NLMSG_DATA returns address of data segment in netlink msg
  strncpy(NLMSG_DATA(nlh), msg, msg_size);

  struct iovec iov;
  iov.iov_base = (void *) nlh;
  iov.iov_len = nlh->nlmsg_len;

  static struct msghdr outermsghdr;
  memset(&outermsghdr, 0, sizeof(struct msghdr));
  outermsghdr.msg_name = (void *) &dest_addr;
  outermsghdr.msg_namelen = sizeof(dest_addr);

  // https://stackoverflow.com/a/57390151/8507296
// #if LINUX_VERSION_CODE < KERNEL_VERSION(3,19,0)
  outermsghdr.msg_iov = &iov;
  outermsghdr.msg_iovlen = 1;
// #else
  // iov_iter_init(&outermsghdr.msg_iter, 1, &iov, 1, sizeof(dest_addr));
// #endif
  
  

  // send to kernel space
  int rc = sendmsg(sock_fd, &outermsghdr, 0);

  if (rc < 0) {
    perror("sendmsg");
  }
  return rc;
}

static void greet_kernel(int sock_fd, char *msg, uint32_t msg_len) {
  send_netlink_msg_to_kernel(sock_fd, msg, msg_len, NLMSG_GREET, NLM_F_ACK);
}

int main(int argc, char const *argv[]) {
  int choice;
  int sock_fd;

  sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_TEST_PROTOCOL);

  if (sock_fd == -1) {
    perror("create_netlink_socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_nl src_addr;
  struct nlmsghdr *nlh = NULL;

  memset(&src_addr, 0, sizeof(src_addr));

  src_addr.nl_family = AF_NETLINK;
  src_addr.nl_pid = getpid();

  if (bind(sock_fd, (struct sockaddr *) &src_addr, sizeof(src_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  while(1) {
    printf("Menu: \n1. Greet Kernel\n2. Exit");
    scanf("%d\n", &choice);

    switch (choice) {
    case 1:
      char user_msg[MAX_PAYLOAD] = {"Hi There whats up"};
      if (fgets(user_msg, MAX_PAYLOAD, stdin) == NULL) {
        printf("error");
        return EXIT_FAILURE;
      }
      greet_kernel(sock_fd, user_msg, strlen(user_msg));
      break;
    
    case 2:
      close(sock_fd);
      break;
    default:
      break;
    }
  }

  return 0;
}


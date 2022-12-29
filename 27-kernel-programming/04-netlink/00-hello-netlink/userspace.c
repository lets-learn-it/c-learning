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

#define MAX_PAYLOAD 2048
#define NETLINK_TEST_PROTOCOL 31
#define NLMSG_GREET 1

typedef struct thread_arg_{
  int sock_fd;
} thread_arg_t;

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

static void * _start_kernel_data_receiver_thread(void *arg){

  int rc = 0;
  struct iovec iov;
  struct nlmsghdr *nlh_recv = NULL;
  static struct msghdr outermsghdr;
  int sock_fd = 0;

  // get socket fd which was passed in args
  thread_arg_t *thread_arg = (thread_arg_t *)arg;
  sock_fd = thread_arg->sock_fd;

  /*Take a new buffer to recv data from kernel*/
  nlh_recv = (struct nlmsghdr *)calloc(1, NLMSG_HDRLEN + NLMSG_SPACE(MAX_PAYLOAD));
  
  do{
    /* Since, USA is receiving the msg from KS, so, just leave all
      * fields of nlmsghdr empty. they shall be filled by kernel
      * while delivering the msg to USA*/
    memset(nlh_recv, 0, NLMSG_HDRLEN + NLMSG_SPACE(MAX_PAYLOAD));
    
    iov.iov_base = (void *)nlh_recv;
    iov.iov_len = NLMSG_HDRLEN + NLMSG_SPACE(MAX_PAYLOAD);

    memset(&outermsghdr, 0, sizeof(struct msghdr));
    
    outermsghdr.msg_iov     = &iov;
    outermsghdr.msg_name    = NULL;
    outermsghdr.msg_iovlen  = 1;
    outermsghdr.msg_namelen = 0;

    /* Read message from kernel. Its a blocking system call 
      * Application execuation is suspended at this point 
      * and would not resume until it receives linux kernel
      * msg. We can configure recvmsg() to not to block, 
      * but lets use it in blocking mode for now */

    rc = recvmsg(sock_fd, &outermsghdr, 0);

    /* We have successfully received msg from linux kernel*/
    /* print the msg from kernel. kernel msg shall be stored 
      * in outermsghdr.msg_iov->iov_base
      * in same format : that is Netlink hdr followed by payload data*/
    nlh_recv = outermsghdr.msg_iov->iov_base;
    char *payload = NLMSG_DATA(nlh_recv);

    printf("Received Netlink msg from kernel, bytes recvd = %d\n", rc);
    printf("msg recvd from kernel = %s\n", payload);
  } while(1);
}

void start_kernel_data_receiver_thread(thread_arg_t *thread_arg){

    pthread_attr_t attr;
    pthread_t recv_pkt_thread;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&recv_pkt_thread, &attr,
            &_start_kernel_data_receiver_thread,
            (void *)thread_arg);
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

  // for receiving data, start new thread
  thread_arg_t thread_arg;
  thread_arg.sock_fd = sock_fd;
  start_kernel_data_receiver_thread(&thread_arg);

  while(1) {
    printf("Menu: \n1. Greet Kernel\n2. Exit\n");
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


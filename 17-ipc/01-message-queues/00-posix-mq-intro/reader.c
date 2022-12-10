#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  mqd_t mqd;
  struct mq_attr attr;
  const char msg[20] = "Hello, World";

  // name of queue should be like /something
  if((mqd = mq_open("/my_mq", O_RDONLY)) == -1) {
    perror("mq_open");
    exit(1);
  }

  if(mq_getattr(mqd, &attr) == -1) {
    perror("mq_getattr");
    mq_close(mqd);
    exit(1);
  }

  char *buffer = calloc(attr.mq_msgsize, 1);

  unsigned int priority = 0;

  if(mq_receive(mqd, buffer, attr.mq_msgsize, &priority) == -1) {
    perror("mq_receive");
  }

  printf("%s", buffer);

  mq_close(mqd);
  return 0;
}

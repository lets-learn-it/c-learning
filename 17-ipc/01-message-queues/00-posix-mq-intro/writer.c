#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  mqd_t mqd;

  // name of queue should be like /something
  if((mqd = mq_open("/my_mq", O_CREAT | O_EXCL | O_WRONLY, 0600, NULL)) == -1) {
    perror("mq_open");
    exit(1);
  }

  // send msg with priority 10
  // 6 length of HELLO\0
  mq_send(mqd, "HELLO", 6, 10);

  mq_close(mqd);
  return 0;
}

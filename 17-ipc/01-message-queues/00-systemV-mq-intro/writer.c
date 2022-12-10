#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Message {
  long msgtype;
  char buffer[100];
};

int main(int argc, char const *argv[]) {
  key_t key;
  int nbytes;
  int msgq;
  const char *msg = "Parikshit";
  struct Message message;

  // while receiving, receiver will specify this id
  message.msgtype = 2;

  strcpy(message.buffer, msg);

  if((key = ftok("./queue.txt", 'B')) == -1) {
    perror("ftok");
    exit(1);
  }

  if ((msgq = msgget(key, 0777 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }

  if((nbytes = msgsnd(msgq, &message, strlen(msg) + 1, 0)) == -1) {
    perror("msgsnd");
    exit(1);
  }

  return 0;
}

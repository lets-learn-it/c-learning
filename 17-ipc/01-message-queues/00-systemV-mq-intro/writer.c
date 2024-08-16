#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "message.h"

int main(int argc, char const *argv[]) {
  key_t key;
  int nbytes;
  int msgq;
  const char *msg = "Parikshit";
  struct Message message;

  // while receiving, receiver will specify this id
  message.msgid = 2;

  strncpy(message.p.name, msg, sizeof(msg)+1);
  message.p.age = 25;

  if((key = ftok("./queue.txt", 'B')) == -1) {
    perror("ftok");
    exit(1);
  }

  if ((msgq = msgget(key, 0777 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }

  if((nbytes = msgsnd(msgq, &message, sizeof(person), 0)) == -1) {
    perror("msgsnd");
    exit(1);
  }

  return 0;
}

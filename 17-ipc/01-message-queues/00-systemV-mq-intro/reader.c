#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include "message.h"

int main(int argc, char const *argv[]) {
  key_t key;
  int n = 11;
  struct Message message;
  int msgq;

  if((key = ftok("./queue.txt", 'B')) == -1) {
    perror("ftok");
    exit(1);
  }

  if ((msgq = msgget(key, 0777 | IPC_CREAT)) == -1) {
    perror("msgget");
    exit(1);
  }
  
  // get message of type 2
  msgrcv(msgq, &message, sizeof(message), 2, 0);

  person p = (person) message.p;
  printf("msg id: %ld and person: (%s, %d)\n", message.msgid, p.name, p.age);
  return 0;
}
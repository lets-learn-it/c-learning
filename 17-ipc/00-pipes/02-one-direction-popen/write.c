#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***********************************************************************************
 * Will run command i.e. grap which will find demo in inputed text to parent process
 * parent process will give that text to child. child will find lines with 'demo'
 * and put it in file demo.txt
 * when you want to close stdin, use ctrl + d
 ***********************************************************************************/

int main(int argc, char const *argv[]) {
  FILE *fp;
  char buffer[1024];

  char *command = "grep demo /dev/stdin > demo.txt";

  if((fp = popen(command, "w")) == NULL) {
    perror("popen");
    exit(1);
  }

  while(fgets(buffer, 1024, stdin) != NULL) {
    fprintf(stdout, "%s", buffer);
    if(fputs(buffer, fp) == EOF) {
      perror("fputs");
    }
  }

  pclose(fp);
  return 0;
}

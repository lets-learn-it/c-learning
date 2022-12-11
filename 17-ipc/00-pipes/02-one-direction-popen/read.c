#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********************************************************
 * Will run cmd as different process and read all stdout
 * parent process will print stdout of child on its stdout
 **********************************************************/

int main(int argc, char const *argv[]) {
  FILE *fp;
  char buffer[1024];
  char *cmd = "ls";

  if((fp = popen(cmd, "r")) == NULL) {
    perror("popen");
    exit(1);
  }

  while(fgets(buffer, 1024, fp) != NULL) {
    fprintf(stdout, "%s", buffer);
  }

  pclose(fp);
  return 0;
}

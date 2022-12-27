#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void exit1() {
  static int num = 0;
  fprintf(stdout, "exit1 %d\n", num);
  num++;
}

void exit2() {
  fprintf(stdout, "exit2...\n");
}

int main(int argc, char const *argv[]) {
  atexit(&exit1);
  atexit(&exit1);
  atexit(&exit2);  // this will run first
  return 0;
}

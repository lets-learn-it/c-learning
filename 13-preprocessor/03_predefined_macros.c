#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("filename: %s\n", __FILE__);

  printf("line: %d\n", __LINE__);
  printf("function: %s\n", __func__);

  printf("date: %s\n", __DATE__);
  printf("time: %s\n", __TIME__);
  return 0;
}

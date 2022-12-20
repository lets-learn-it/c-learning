#include <stdio.h>

int main(int argc, char const *argv[]) {
  extern char name[20];
  printf("%s\n", name);

  extern char* get_name();
  printf("%s", get_name());
  return 0;
}

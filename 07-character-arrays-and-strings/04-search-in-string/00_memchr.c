#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s[] = "This is d. This is Demo Demo Demo";

  char *tmp = memchr(s, 'D', strlen(s));
  if (tmp != NULL) fprintf(stderr, "%s\n", tmp);
  
  return 0;
}

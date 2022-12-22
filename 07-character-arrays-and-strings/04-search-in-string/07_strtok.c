#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s1[] = "Tokenize this string using spaces and punctuation marks.";

  char *tmp;

  tmp = strtok(s1, " .!?,");

  while(tmp != NULL) {
    fprintf(stderr, "%s\n", tmp);
    tmp = strtok(NULL, " .!?,");
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s[] = "This is d. This is Demo Demo Demo";

  char *tmp = strchr(s, 'D');
  if (tmp != NULL) fprintf(stderr, "%s (%ld)\n", tmp, tmp-s+1);

  // find next occurence
  tmp = strchr(tmp+1, 'D');
  if (tmp != NULL) fprintf(stderr, "%s (%ld)\n", tmp, tmp-s+1);
  
  return 0;
}

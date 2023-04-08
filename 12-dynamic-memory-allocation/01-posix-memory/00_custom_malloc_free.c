#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

void * xmalloc (int size) {
  void *p = sbrk(0);

  if (sbrk(size) == NULL)
    return NULL;
  return p;
}

/* 
 * It is not capable of pointer in between. It can only free last xmalloced block
 */
void xfree(int nbytes) {
  assert(nbytes > 0);
  sbrk(nbytes * -1);
}

int main(int argc, char const *argv[]) {
  char *p = (char *) xmalloc(20);

  char source[] = "Hello, World!";

  strncpy(p, source, strlen(source));
  printf("%s", p);
  
  xfree(20);
  return 0;
}

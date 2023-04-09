#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

/* 
 * struct rlimit {
 *   rlim_t rlim_cur;  // Soft limit 
 *   rlim_t rlim_max;  // Hard limit (ceiling for rlim_cur)
 * };
 * 
 * rlim_cur & rlim_max are set to -1 when resource limit is unlimited.
 */

int main () {
  /* process's virtual memory/address space limit. */
  struct rlimit aslimit;

  /* Change condition if want to change limit */
  if (1 == 1) {
    aslimit.rlim_cur = 1024*1024*5;
    aslimit.rlim_max = -1;

    setrlimit(RLIMIT_AS, &aslimit);
  }

  if (getrlimit(RLIMIT_AS, &aslimit) == -1) {
    perror("getrlimit");
    return -1;
  }

  printf("Soft limit: %ld, Hard limit: %ld\n", aslimit.rlim_cur, aslimit.rlim_max);

  char *s = "Hello, World!";

  /* let do malloc. If memory not available, malloc will fail. */
  char *p = (char *) malloc(20);
  perror("malloc");
  
  strncpy(p, s, strlen(s));
  return 0;
}
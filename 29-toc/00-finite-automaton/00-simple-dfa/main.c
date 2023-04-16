#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

int main(int argc, char const *argv[]) {
  /* a(bb)+a */
  State start, s1, s2, s3, s4;

  /* initialize states */
  initState(&start, "start", 0);
  initState(&s1, "s1", 0);
  initState(&s2, "s2", 0);
  initState(&s3, "s3", 0);
  initState(&s4, "s4", 1);  /* this is final state */

  /* Add transitions */
  addTransition(&start, &s1, 'a');
  addTransition(&s1, &s2, 'b');
  addTransition(&s2, &s3, 'b');
  addTransition(&s3, &s2, 'b');
  addTransition(&s3, &s4, 'a');

  printf("%d", runMachine(&start, argv[1]));
  return 0;
}

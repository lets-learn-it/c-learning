#include <stdio.h>
#include <stdlib.h>

#define LIMIT 5
#define PI 3.14
#define DISPLAY printf("Hello, World!\n");

// macros can be used in macro
#define PISQUARE PI*PI

// multiline macro
#define multiline "This is \
very long \
message"

int main() {
  int counter;
  for (counter=1;counter<=LIMIT;counter++) {
    printf("%d\n", counter);
  }

  DISPLAY

  printf("%f\n", PISQUARE);

  printf("%s", multiline);
  return 0;
}
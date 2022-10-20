#include <stdio.h>

void function() {
  printf("Oh, no! This line repeats\n");
}

int main() {
  int i;

  for(i=0;i<5;i++) {
    function();
  }
  
  return 0;
}
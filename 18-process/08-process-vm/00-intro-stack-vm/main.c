#include <stdio.h>
#include <stdlib.h>
#include "vm.h"



int main(int argc, char const *argv[]) {
  int code[] = {
    ICONST, 99, 
    ICONST, 85,
    IADD,
    PRINT, 
    ICONST, 85,
    GSTORE, 0,
    GLOAD, 0,
    HALT
  };

  VM vm;
  init(&vm, code, 13, 0);
  trace(&vm, 1);
  
  cpu(&vm);
  return 0;
}

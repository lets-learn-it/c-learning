#include <stdio.h>
#include <stdlib.h>
#include "vm.h"



int main(int argc, char const *argv[]) {
  int fact = 0;
  int code[] = {
  /* def fact: ARGS=1, LOCALS=0       ADDRESS */
  /*    If N < 2 RETURN 1                     */
        LOAD, -3,                     /* 00 */
        ICONST, 2,                    /* 02 */ 
        ILT,                          /* 04 */
        BRF, 10,                      /* 05 */
        ICONST, 1,                    /* 07 */
        RET,                          /* 09 */
  /*    else                                  */
  /*      RETURN N * FACT(N-1)                */
        LOAD, -3,                     /* 10 */
        LOAD, -3,                     /* 12 */
        ICONST, 1,                    /* 14 */
        ISUB,                         /* 16 */
        CALL, fact, 1,                   /* 17 */
        IMUL,                         /* 20 */
        RET,                          /* 21 */
  /* def main: ARGS=0, LOCALs=0               */
  /*   PRINT FACT(5)                          */
        ICONST, 10,                    /* 22 */
        CALL, fact, 1,                   /* 24 */
        PRINT,                        /* 27 */
        HALT                          /* 28 */
  };

  VM vm;
  init(&vm, code, 29, 22);
  trace(&vm, 1);
  
  cpu(&vm);
  return 0;
}

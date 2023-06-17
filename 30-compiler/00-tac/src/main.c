#include "include/lexer.h"
#include "include/macros.h"
#include "include/tac.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("argc < 2");
    return 1;
  }

  tac_compile_file(argv[1]);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Lexer.h"



int main(int argc, char const *argv[]) {
  char input[100];
  scanf("%s", input);
  Token *token;
  int pos = 0;
  // while(true) {
    while(true) {
      token = nextToken(input, &pos);
      if (token->type == END_OF_INPUT) break;
      print_token(token);
      free(token);
    }
    free(token);
  // }
  
  return 0;
}

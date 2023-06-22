#include "Lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Token* nextToken(char *input, int *pos) {
  Token *token = (Token *) malloc(sizeof(Token));

  /* eat whitespaces */
  while(input[*pos] == ' ') {
    *pos ++;
  }

  switch (input[*pos]) {
  case '+':
    token->type = BINARY_OPERATOR;
    strncpy(token->lexem, (const char*) input + *pos, 1);
    break;
  case '\0':
    token->type = END_OF_INPUT;
    strncpy(token->lexem, (const char*) input + *pos, 1);
    break;
  default:
    strncpy(token->lexem, (const char*) input + *pos, 1);
    token->type = OPERAND;
    break;
  }
  (*pos) ++;
  return token;
}

void print_token(Token *token) {
  printf("{Lexem: %s}\n", token->lexem);
}

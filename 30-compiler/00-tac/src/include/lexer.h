#ifndef TAC_LEXER_H
#define TAC_LEXER_H

#include "token.h"
#include <stddef.h>

typedef struct LEXER_STRUCT {
  char *src;
  size_t ssize;
  char current;
  unsigned int index;
} lexer_T;

lexer_T* init_lexer(char* src);
void lexer_advance(lexer_T* lexer);
char lexer_peek(lexer_T* lexer, int offset);
token_T* lexer_advance_current(lexer_T* lexer, int type);
token_T* lexer_advance_with(lexer_T* lexer, token_T* token);
void lexer_skip_whitespace(lexer_T* lexer);
token_T* lexer_parse_id(lexer_T* lexer);
token_T* lexer_parse_number(lexer_T* lexer);
token_T* lexer_next_token(lexer_T* lexer);

#endif
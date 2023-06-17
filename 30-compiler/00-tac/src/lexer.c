#include "include/lexer.h"
#include "include/macros.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

lexer_T* init_lexer(char* src) {
  lexer_T* lexer = calloc(1, sizeof(lexer_T));
  lexer->index = 0;
  lexer->src = src;
  lexer->ssize = strlen(src);
  lexer->current = lexer->src[lexer->index];

  return lexer;
}

void lexer_advance(lexer_T* lexer) {
  if (lexer->current != '\0') {
    lexer->index += 1;
    lexer->current = lexer->src[lexer->index];
  }
}

char lexer_peek(lexer_T* lexer, int offset) {
  return lexer->src[MIN(lexer->index + offset, lexer->ssize)];
}

token_T* lexer_advance_with(lexer_T* lexer, token_T* token) {
  lexer_advance(lexer);
  return token;
}

token_T* lexer_advance_current(lexer_T* lexer, int type) {
  char *value = calloc(2, sizeof(char));
  value[0] = lexer->current;
  value[1] = '\0';

  token_T* token = init_token(value, type);
  lexer_advance(lexer);

  return token;
}

void lexer_skip_whitespace(lexer_T* lexer) {
  while (lexer->current == '\r' || lexer->current == '\n' || lexer->current == ' ' || lexer->current == '\t') {
    lexer_advance(lexer);
  }
}

token_T* lexer_parse_id(lexer_T* lexer) {
  char* value = calloc(1, sizeof(char));
  while (isalnum(lexer->current)) {
    value = realloc(value, (strlen(value)+2)*sizeof(char));
    strcat(value, (char[]){lexer->current, 0});
    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_ID);
}

token_T* lexer_parse_number(lexer_T* lexer) {
  char* value = calloc(1, sizeof(char));
  while (isdigit(lexer->current)) {
    value = realloc(value, (strlen(value)+2)*sizeof(char));
    strcat(value, (char[]){lexer->current, 0});
    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_INT);
}

token_T* lexer_next_token(lexer_T* lexer) {
  while (lexer->current != '\0') {
    lexer_skip_whitespace(lexer);
    if (isalpha(lexer->current))
      return lexer_parse_id(lexer);

    if (isdigit(lexer->current))
      return lexer_parse_number(lexer);

    switch (lexer->current) {
    case '=':
      if (lexer_peek(lexer, 1) == '>') return lexer_advance_with(lexer, init_token("=>", TOKEN_RIGHT_ARROW));
      return lexer_advance_with(lexer, init_token("=", TOKEN_EQUALS));
      break;
    
    case '(': return lexer_advance_current(lexer, TOKEN_LPAREN);
    case ')': return lexer_advance_current(lexer, TOKEN_RPAREN);
    case '{': return lexer_advance_current(lexer, TOKEN_LBRACE);
    case '}': return lexer_advance_current(lexer, TOKEN_RBRACE);
    case ':': return lexer_advance_current(lexer, TOKEN_COLON);
    case ',': return lexer_advance_current(lexer, TOKEN_COMMA);
    case '<': return lexer_advance_current(lexer, TOKEN_LT);
    case '>': return lexer_advance_current(lexer, TOKEN_GT);
    case ';': return lexer_advance_current(lexer, TOKEN_SEMI);
    
    case '\0': break;
    default: 
      printf("[Lexer]: Unexpected character `%s`\n", lexer->current);
      exit(1);
    }
  }
  return init_token(0, TOKEN_EOF);
}

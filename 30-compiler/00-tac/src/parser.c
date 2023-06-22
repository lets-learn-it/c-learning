#include "include/parser.h"
#include "include/AST.h"
#include "include/list.h"
#include "include/types.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

parser_T* init_parser(lexer_T* lexer) {
  parser_T* parser = calloc(1, sizeof(parser_T));
  parser->lexer = lexer;
  parser->token = lexer_next_token(lexer);

  return parser;
}

token_T* parser_eat(parser_T* parser, int type) {
  if (parser->token->type != type) {
    printf("Parser [%d]: Unexpected token: `%s`, was expecting `%s`", __LINE__, token_to_str(parser->token), token_type_to_str(parser->token->type));
    exit(1);
  }

  parser->token = lexer_next_token(parser->lexer);
  return parser->token;
}

AST_T*  parser_parse(parser_T* parser) {
  return parser_parse_compound(parser);
}

AST_T*  parser_parse_id(parser_T* parser) {
  char* value = calloc(strlen(parser->token->value) + 1, sizeof(char));
  strcpy(value, parser->token->value);
  parser_eat(parser, TOKEN_ID);
  
  if (parser->token->type == TOKEN_EQUALS) {
    parser_eat(parser, TOKEN_EQUALS);
    AST_T* ast = init_ast(AST_ASSIGNMENT);
    ast->name = value;
    printf("--> %s\n", ast->name);
    ast->value = parser_parse_expr(parser);
    return ast;
  }

  AST_T* ast = init_ast(AST_VARIABLE);
  ast->name = value;

  if (parser->token->type == TOKEN_COLON) {
    parser_eat(parser, TOKEN_COLON);

    while(parser->token->type == TOKEN_ID) {
      ast->data_type = typename_to_int(parser->token->value);
      parser_eat(parser, TOKEN_ID);

      if (parser->token->type == TOKEN_LT) {
        parser_eat(parser, TOKEN_LT);
        ast->data_type = typename_to_int(parser->token->value);
        parser_eat(parser, TOKEN_ID);
        parser_eat(parser, TOKEN_GT);
      }
    }
  }
  return ast;
}

AST_T* parser_parse_list(parser_T* parser) {
  parser_eat(parser, TOKEN_LPAREN);
  AST_T* compound = init_ast(AST_COMPOUND);
  list_push(compound->children, parser_parse_expr(parser));
  while (parser->token->type == TOKEN_COMMA) {
    parser_eat(parser, TOKEN_COMMA);
    list_push(compound->children, parser_parse_expr(parser));
  }
  parser_eat(parser, TOKEN_RPAREN);
  return compound;
}

AST_T*  parser_parse_expr(parser_T* parser) {
  switch (parser->token->type)
  {
  case TOKEN_ID: return parser_parse_id(parser);
  case TOKEN_LPAREN: return parser_parse_list(parser);
  
  default:
    printf("[Parser]: Unexpected token `%s` \n", token_to_str(parser->token));
    exit(1);
  }
}

AST_T* parser_parse_compound(parser_T* parser) {
  AST_T* compound = init_ast(AST_COMPOUND);
  while (parser->token->type != TOKEN_EOF) {
    list_push(compound->children, parser_parse_expr(parser));
  }
  return compound;
}
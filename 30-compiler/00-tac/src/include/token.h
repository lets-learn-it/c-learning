#ifndef TAC_TOKEN_H
#define TAC_TOKEN_H

typedef enum {
    TOKEN_ID,
    TOKEN_EQUALS,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_RIGHT_ARROW,
    TOKEN_INT,
    TOKEN_SEMI,
    TOKEN_EOF
} type_T;

typedef struct TOKEN_STRUCT {
  char *value;
  type_T type;
} token_T;


token_T* init_token(char* value, int type);
char* token_to_str(token_T* token);
char* token_type_to_str(int type);

#endif


#ifndef __LEXER__
#define __LEXER__

#define true 1
#define false 0

typedef enum {
  OPERAND,
  BINARY_OPERATOR,
  UNARY_OPERATOR,
  END_OF_INPUT
} Type;

typedef enum {
  BIT_XOR = 0,     /* ^ */
  BIT_AND_OR,      /* & | */
  EQUALITY,        /* == != */
  RELATIONAL,      /* < <= > >= */
  BIT_SHIFT,       /* << >> */
  ADD_SUB,         /* + - */
  MUL_DIV,         /* * / % */
  UNARY,           /* + - ! ~ ++ -- * & (type) sizeof */
  PAREN_BRACE_POST /* () {} [] -> . ++ -- */
} Precedence;

// const char* PrecedenceStr[] = {
//   "BIT_XOR",
//   "BIT_AND_OR",
//   "EQUALITY",
//   "RELATIONAL",
//   "BIT_SHIFT",
//   "ADD_SUB",
//   "MUL_DIV",
//   "UNARY",
//   "PAREN_BRACE_POST"
// };

typedef enum {
  LEFT,
  RIGHT
} Associativity;

typedef struct t_ {
  char lexem[6];
  Type type;
  Precedence precedence;
  Associativity associativity;
} Token;

Token* nextToken(char *input, int *pos);
void print_token(Token *token);

#endif
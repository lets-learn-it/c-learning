#include "include/AST.h"
#include <stdlib.h>

AST_T* init_ast(int type) {
  AST_T* ast = calloc(1, sizeof(AST_T));

  ast->type = type;
  if (type == AST_COMPOUND)
    ast->children = init_list(sizeof(AST_T*));
  return ast;
}
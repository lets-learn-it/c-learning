#include "gldll.h"
#include <stdlib.h>

void gldll_add(gldll_t *lst, gldll_node_t *node) {
  if (lst->head == NULL) {
    lst->head = node;
    return;
  }

  gldll_node_t *current = lst->head;

  while(current->right) {
    current = current->right;
  }
  current->right = node;
  node->left = current;
}

void print(gldll_t *lst, void (*fn)(gldll_node_t *node)) {
  gldll_node_t *current = lst->head;

  while(current) {
    fn(current);
    current = current->right;
  }
}
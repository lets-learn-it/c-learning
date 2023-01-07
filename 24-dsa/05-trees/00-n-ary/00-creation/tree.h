
#include "dll.h" /* 02-linked-lists/01-doubly-linked-list/dll.h */

typedef struct tnode {
  void *data;
  dll children;
} TreeNode;

typedef struct tree {
  TreeNode *root;

  /* Operations */
  void (*add) (struct tree *self, TreeNode *parent, TreeNode *node);
  void (*print) (struct tree *self, void (*fn) (void *data));
} Tree;

void initialize_tree(Tree *tree);
TreeNode * create_tree_node(void *data);
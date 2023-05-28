
#ifndef __BST__

#define __BST__

#define true 1
#define false 0
#define bool int

enum Position {
  NONE,
  LEFT,
  RIGHT
};

typedef struct bstnode {
  void *key;
  void *value;
  struct bstnode *left;
  struct bstnode *right;
  struct bstnode *parent;
} BSTNode;

typedef struct bst {
  BSTNode *root;

  // operations
  void (*insert) (struct bst *self, BSTNode *node);
  int (*compare) (void *existing_key, void *new_key); /* 1, greater than, -1 less than, 0 equal */
  void (*preorder) (struct bst *self, void (*fn) (void *key, void *value));
  void (*postorder) (struct bst *self, void (*fn) (void *key, void *value));
  void (*inorder) (struct bst *self, void (*fn) (void *key, void *value));
  bool (*find) (struct bst *self, void *key);
  BSTNode* (*delete_node) (BSTNode *node);
  int (*count_nodes) (struct bst *self);
}BST;

void initialize_bst(BST *bst, int (*compare) (void *old, void *new_data));
BSTNode * create_bst_node(void *key, void *value);

#endif
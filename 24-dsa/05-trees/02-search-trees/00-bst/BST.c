#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

enum Position get_position(BSTNode *parent, BSTNode *child) {
  if (parent->left == child) return LEFT;
  else if(parent->right == child) return RIGHT;
  return NONE;
}

bool add_to(BSTNode *parent, BSTNode *child, enum Position pos) {
  if (parent == NULL || child == NULL) return false;

  if (pos == LEFT && parent->left == NULL) {
    parent->left = child;
    child->parent = parent;
    return true;
  } else if(pos == RIGHT && parent->right == NULL) {
    parent->right = child;
    child->parent = parent;
    return true;
  }
  return false;
}

void insert (struct bst *self, BSTNode *node) {
  if (self->root == NULL) {
    self->root = node;
    return;
  }

  BSTNode *current = self->root;
  while(current) {
    if (self->compare(current->key, node->key) == 1) {
      if (add_to(current, node, RIGHT)) {
        return;
      }
      current = current->right;
    } else if(self->compare(current->key, node->key) == -1) {
      if (add_to(current, node, LEFT)) {
        return;
      }
      current = current->left;
    } else return;
  }
}

void _preorder (BSTNode *node, void (*fn) (void *key, void *value)) {
  if (node == NULL) return;
  fn(node->key, node->value);
  _preorder(node->left, fn);
  _preorder(node->right, fn);
}

void preorder (struct bst *self, void (*fn) (void *key, void *value)) {
  if (self != NULL) _preorder(self->root, fn);
}

void _postorder (BSTNode *node, void (*fn) (void *key, void *value)) {
  if (node == NULL) return;
  _postorder(node->left, fn);
  _postorder(node->right, fn);
  fn(node->key, node->value);
}

void postorder (struct bst *self, void (*fn) (void *key, void *value)) {
  if (self != NULL) _postorder(self->root, fn);
}

void _inorder (BSTNode *node, void (*fn) (void *key, void *value)) {
  if (node == NULL) return;
  _inorder(node->left, fn);
  fn(node->key, node->value);
  _inorder(node->right, fn);
}

void inorder (struct bst *self, void (*fn) (void *key, void *value)) {
  if (self != NULL) _inorder(self->root, fn);
}

BSTNode* _not_null_child_or_null(BSTNode *node) {
  if (node->left != NULL && node->right != NULL) {
    fprintf(stderr, "[ERROR] Node has both children\n");
    exit(1);
  }

  if (node->left != NULL) return node->left;
  return node->right;
}

void _delete_one_or_nochild_node(BSTNode *node) {
  enum Position pos = get_position(node->parent, node);
  BSTNode *child = _not_null_child_or_null(node);
  BSTNode *parent = node->parent;

  node->parent = NULL;
  node->right = NULL;
  node->left = NULL;

  if (pos == LEFT) {
    parent->left = child;
    return;
  } else if (pos == RIGHT) {
    parent->right = child;
    return;
  }
}

BSTNode* _find_smallest_descendant(BSTNode *node) {
  if (node == NULL) return NULL;

  while(node->left) {
    node = node->left;
  }
  return node;
}

void _detach_and_attach(BSTNode *node1, BSTNode *node2) {
  // change parent
  node2->parent = node1->parent;
  node1->parent->right = node2;
  node2->left = node1->left;

  if (node1->right == node2) node2->right = NULL;
  else node2->right = node1->right;

  // clean node1's references
  node1->parent = NULL;
  node1->left = NULL;
  node1->right = NULL;
}

BSTNode* delete_node (BSTNode *node) {
  if (node == NULL) return NULL;

  // if node has both children,
  if (node->right != NULL && node->left != NULL) {
    BSTNode *smallest = _find_smallest_descendant(node->right);
    _detach_and_attach(node, smallest);
  } else {
    _delete_one_or_nochild_node(node);
  }
  return node;
}

bool _find(BST *self, BSTNode *node, void *key) {
  while(node) {
    if (self->compare(node->key, key) == 0) return true;
    else if (self->compare(node->key, key) > 0) node = node->right;
    else node = node->left;
  }
  return false;
}

bool find (struct bst *self, void *key) {
  if (self != NULL) return _find(self, self->root, key);
  return false;
}

void initialize_bst(BST *bst, int (*compare) (void *existing_key, void *new_key)) {
  bst->root = NULL;
  bst->compare = compare;
  bst->insert = &insert;
  bst->preorder = &preorder;
  bst->postorder = &postorder;
  bst->inorder = &inorder;
  bst->find = &find;
  bst->delete_node = &delete_node;
}

BSTNode * create_bst_node(void *key, void *value) {
  BSTNode *node = malloc(sizeof(BSTNode));
  node->value = value;
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}
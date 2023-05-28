#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

bool add_to(BSTNode *parent, BSTNode *child, enum Position pos) {
  if (parent == NULL || child == NULL) return false;

  if (pos == LEFT && parent->left == NULL) {
    parent->left = child;
    return true;
  } else if(pos == RIGHT && parent->right == NULL) {
    parent->right = child;
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
}

BSTNode * create_bst_node(void *key, void *value) {
  BSTNode *node = malloc(sizeof(BSTNode));
  node->value = value;
  node->key = key;
  return node;
}
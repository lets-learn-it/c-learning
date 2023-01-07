#include "tree.h"
#include <stdlib.h>
#include "queue.h"

void add (struct tree *self, TreeNode *parent, TreeNode *child) {
  if (parent == NULL) {  /* only root can have no parent */
    self->root = child;
    return;
  }
  dll_node *node = create_dll_node(child);
  parent->children.add_last(&(parent->children), node);
}

void print_tree (struct tree *self, void (*fn) (void *data)) {
  queue q;
  TreeNode *tnode;
  initialize(&q);

  /* put root in queue */
  queue_node *node = create_queue_node(self->root);
  q.enqueue(&q, node);

  while (q.get_front(&q) != NULL) {
    /* dequeue */
    tnode = (TreeNode *) q.dequeue(&q)->data;
    fn(tnode->data);

    // /* enqueue all childred */
    // while ()
  }
}

void initialize_tree(Tree *tree) {
  tree->add = &add;
  tree->print = &print_tree;
  tree->root = NULL;
}

TreeNode * create_tree_node(void *data) {
  TreeNode *node = malloc(sizeof(TreeNode));
  node->data = data;
  initialize_dll(&(node->children));
  return node;
}


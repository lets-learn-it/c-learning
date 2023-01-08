#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
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
  dll_node *dnode;
  TreeNode *tnode;
  initialize(&q);

  /* put root in queue */
  queue_node *node = create_queue_node(self->root);
  q.enqueue(&q, node);

  while (q.get_front(&q) != NULL) {
    /* dequeue */
    tnode = (TreeNode *) q.dequeue(&q)->data;
    fn(tnode->data);
    printf("\n");

    dnode = tnode->children.head;

    /* enqueue all children */
    while (dnode != NULL) {
      /* build queue_node & enqueue */
      q.enqueue(&q, create_queue_node(dnode->data));

      dnode = dnode->next;
    }
  }
}

void visualize_tree(TreeNode *parent, void (*fn) (void *data), int level) {
  dll_node *dnode;
  TreeNode *node;

  for (int i=0;i<level-1;i++) {
    printf(" │ ");
  }
  if (level>0) printf(" ├ ");

  fn(parent->data);

  printf("\n");

  dnode = parent->children.head;
  while (dnode != NULL) {
    node = (TreeNode *) dnode->data;
    visualize_tree(node, fn, level+1);
    dnode = dnode->next;
  }
}

void initialize_tree(Tree *tree) {
  tree->add = &add;
  tree->print = &print_tree;
  tree->visualize = &visualize_tree;
  tree->root = NULL;
}

TreeNode * create_tree_node(void *data) {
  TreeNode *node = malloc(sizeof(TreeNode));
  node->data = data;
  initialize_dll(&(node->children));
  return node;
}


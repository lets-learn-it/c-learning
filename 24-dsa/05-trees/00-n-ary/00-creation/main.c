#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tree.h"

int DEBUG = 0;

typedef struct Person {
  char *name;
  char *mother;
} Person;

void print_fn(void *data) {
  Person *person = (Person *) data;
  if (person->mother == NULL) {
    fprintf(stdout, "%s", person->name);
    return ;
  }
  fprintf(stdout, "%s पुत्र %s", person->mother, person->name);
}

int searcher(void *key, void *data) {
  Person *person = (Person *) data;
  int age = *(int *)key;
  // if(person->age == age) {
  //   return 1;
  // }
  return 0;
}

int main(int argc, char const *argv[]) {
  
  Tree tree;
  initialize_tree(&tree);

  Person p1;
  p1.name = "दशरथ";
  p1.mother = NULL;
  TreeNode *node1 = create_tree_node((void *) &p1);
  tree.add(&tree, NULL, node1); /* root */

  Person p2;
  p2.name = "शांता";
  p2.mother = "कौशल्या";
  TreeNode *node2 = create_tree_node((void *) &p2);
  tree.add(&tree, node1, node2);

  Person p3;
  p3.name = "श्रीराम";
  p3.mother = "कौशल्या";
  TreeNode *node3 = create_tree_node((void *) &p3);
  tree.add(&tree, node1, node3);

  Person p4;
  p4.name = "भरत";
  p4.mother = "कैकेयी";
  TreeNode *node4 = create_tree_node((void *) &p4);
  tree.add(&tree, node1, node4);

  Person p5;
  p5.name = "लक्ष्मण";
  p5.mother = "सुमित्रा";
  TreeNode *node5 = create_tree_node((void *) &p5);
  tree.add(&tree, node1, node5);

  Person p6;
  p6.name = "शत्रुघ्न";
  p6.mother = "सुमित्रा";
  TreeNode *node6 = create_tree_node((void *) &p6);
  tree.add(&tree, node1, node6);

  Person p7;
  p7.name = "लव";
  p7.mother = "माता सीता";
  TreeNode *node7 = create_tree_node((void *) &p7);
  tree.add(&tree, node3, node7);

  Person p8;
  p8.name = "कुश";
  p8.mother = "माता सीता";
  TreeNode *node8 = create_tree_node((void *) &p8);
  tree.add(&tree, node3, node8);

  Person p9;
  p9.name = "तक्ष";
  p9.mother = "मांडवी";
  TreeNode *node9 = create_tree_node((void *) &p9);
  tree.add(&tree, node4, node9);

  Person p10;
  p10.name = "पुष्कल";
  p10.mother = "मांडवी";
  TreeNode *node10 = create_tree_node((void *) &p10);
  tree.add(&tree, node4, node10);

  Person p11;
  p11.name = "अंगद";
  p11.mother = "उर्मिला";
  TreeNode *node11 = create_tree_node((void *) &p11);
  tree.add(&tree, node5, node11);

  Person p12;
  p12.name = "चित्रकेतु";
  p12.mother = "उर्मिला";
  TreeNode *node12 = create_tree_node((void *) &p12);
  tree.add(&tree, node5, node12);

  Person p13;
  p13.name = "सुबाहु";
  p13.mother = "श्रुतकीर्ति";
  TreeNode *node13 = create_tree_node((void *) &p13);
  tree.add(&tree, node6, node13);

  Person p14;
  p14.name = "श्रुतिसेन";
  p14.mother = "श्रुतकीर्ति";
  TreeNode *node14 = create_tree_node((void *) &p14);
  tree.add(&tree, node6, node14);

  // tree.print(&tree, &print_fn);
  tree.visualize(tree.root, &print_fn, 0);

  return 0;
}

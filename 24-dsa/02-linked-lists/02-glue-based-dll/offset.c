#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* inbuilt offsetof */
#include <stddef.h>

#define offsetof2(struct_name, field_name) \
          (unsigned int) &((struct_name *)NULL)->field_name

typedef struct gldll_node_ {
  /* There is no data member in node */
  struct gldll_node_ *left;
  struct gldll_node_ *right;
} gldll_node_t;

typedef struct emp_ {
  char name[30];
  unsigned int salary;
  char designation[30];
  unsigned int emp_id;

  /* node */
  gldll_node_t glnode;
} emp_t;

void print(gldll_node_t *glnode) {
  int offset = offsetof2(emp_t, glnode);
  // int offset = offsetof(emp_t, glnode);
  
  /**************************************************************************************
   * Before doing subtraction, we need to typecast gldll_node_t to char * 
   * because if we subtract as it is, compiler will thing offset times previous glnode
   * but we want to back only offset times bytes and not glnode.
   **************************************************************************************/
  void *handle = (void *) ((char *) glnode - offset);
  emp_t *emp = (emp_t *) handle;

  printf("Name: %s\n", emp->name);
  printf("Emp Id: %d\n", emp->emp_id);
  printf("Designation: %s\n", emp->designation);
  printf("Salary: %d\n", emp->salary);

}

int main(int argc, char const *argv[]) {

  printf("Offset of emp_id : %d\n", offsetof2(emp_t, glnode));

  printf("Offset of emp_id Using inbuild macro: %ld\n", offsetof(emp_t, glnode));

  /* Print employee structure given glnode */
  emp_t emp;
  emp.salary = 4;
  strcpy(emp.name, "Parikshit Patil");
  emp.emp_id = 12445;
  strcpy(emp.designation, "Software Engineer");

  print(&(&emp)->glnode);

  return 0;
}

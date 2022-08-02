#include<stdio.h>

/* 
  typedef keyword used to provide some meaningful names 
          to the already existing variable
  Syntax: typedef existing_var new_name;

  In our case, we will give name to struct
 */

typedef struct _person {
  char* name;
  int age;
} Person;


int main() {
  // instead of using struct _person p;
  Person p;
  
  p.age = 25;
  p.name = "Parikshit";

  printf("%s, %d", p.name, p.age);
  return 0;
}
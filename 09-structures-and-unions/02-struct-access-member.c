#include<stdio.h>
#include<stdlib.h>

/* 
  member of struct can be accessed using 
  1. `.` : member operator
  2. `->` : pointer operator
 */

typedef struct _person {
  char* name;
  int age;
} Person;


int main() {
  Person p1;
  
  p1.age = 25;
  p1.name = "Parikshit";

  printf("%s, %d\n", p1.name, p1.age);

  printf("%s, %d\n", (&p1)->name, (&p1)->age);

  Person *p2 = malloc(sizeof(Person));

  p2->age = 24;
  p2->name = "PSKP";

  printf("%s, %d\n", (*p2).name, (*p2).age);

  printf("%s, %d\n", p2->name, p2->age);
  return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
  char name[20];
  int age;
};


int main() {
  int *a;  // pointer to integer data

  a = (int*)calloc(5, sizeof(int));

  *a = 10;
  *(a+1) = 20;

  for(int i=0;i<5;i++)
    printf("Value at a (%p): %d\n", a+i, *(a+i));

  // allocating memory for struct
  struct Person *family = (struct Person*) calloc(5, sizeof(struct Person));

  strcpy(family->name, "Parikshit");
  family->age = 24;

  strcpy((family+1)->name, "XYZ");
  (family+1)->age = 22;

  for(int i=0;i<5;i++)
    printf("Person at %p: \n\tName: %s\n\tAge: %d\n", family+i, (family+i)->name, (family+i)->age);

  return 0;
}
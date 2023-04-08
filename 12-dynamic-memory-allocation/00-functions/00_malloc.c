#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
  char name[20];
  int age;
};


int main() {
  int *a;  // pointer to integer data

  a = (int*)malloc(sizeof(int));

  *a = 10;

  printf("Value at a (%p): %d\n", a, *a);

  // allocating memory for struct
  struct Person *person = (struct Person*) malloc(sizeof(struct Person));

  strcpy(person->name, "Parikshit");
  person->age = 24;

  printf("Person at %p: \n\tName: %s\n\tAge: %d\n", person, person->name, person->age);

  return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int age;
  char name[50];
  char address[100];
} Person;

void get_person_details(Person *person) {
  printf("Enter your name: ");
  scanf("%s", person->name);

  printf("Enter your address: ");
  scanf("%s", person->address);

  printf("Enter your age: ");
  scanf("%d", &person->age);

  return;
}

void print(Person *p) {
  printf("\nName: %s\nAddress: %s\nAge: %d\n\n", p->name, p->address, p->age);
}

int main(int argc, char const *argv[]) {
  Person p1;
  get_person_details(&p1);
  print(&p1);

  Person *p2 = malloc(sizeof(Person));

  // check 2 person struct are same
  printf("Compare p1 & p2: %d\n", memcmp(&p1, p2, sizeof(p1)));

  memcpy(p2, &p1, sizeof(p1));

  printf("Compare p1 & p2: %d\n", memcmp(&p1, p2, sizeof(p1)));

  return 0;
}

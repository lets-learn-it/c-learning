#include<stdio.h>

struct Person {
  char* name;
  int age;
};


int main() {
  struct Person p;
  
  p.age = 25;
  p.name = "Parikshit";

  printf("%s, %d", p.name, p.age);
  return 0;
}
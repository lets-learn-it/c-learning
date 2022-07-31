#include<stdio.h>

int main() {
  int choice = 1;

  switch (choice) {
  case 1:
    printf("You chose 1\n");
    break;
  case 2:
    printf("You chose 2\n");
    break;
  default:
    printf("You chose something else\n");
    break;
  }
  
  return 0;
}
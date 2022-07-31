#include<stdio.h>

int main() {
  int marks = 88;

  if(marks >= 80) {
    printf("You got first class...\n");
  } else if(marks >= 40) {
    printf("You Passed...\n");
  } else {
    printf("You Failed...");
  }
  return 0;
}
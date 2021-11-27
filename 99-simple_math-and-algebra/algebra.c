#include"algebra.h"
#include<stdio.h>
#include<string.h>

int evaluate(char exp[]) {
  int length = strlen(exp);

  // considering 0+exp
  int left = 0, right = 0;

  // function pointer so that 
  // we can call correct function 
  int (*last_sign)(int, int) = &sum;

  for(int i=0;i<length;i++){
    
    if(exp[i] == '+') {
      left = (*last_sign)(left, right);
      right = 0;
      last_sign = &sum;
    } else if(exp[i] == '-') {
      left = (*last_sign)(left, right);
      right = 0;
      last_sign = &minus;
    } else {
      right = (exp[i] - '0') + (right * 10);
    }
  }
  
  return (*last_sign)(left, right);
}
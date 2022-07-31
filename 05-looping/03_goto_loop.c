#include<stdio.h>

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int i = 0;

label:
  printf("%d ", arr[i]);
  i++;

  if(i<10)
    goto label;

  return 0;
}
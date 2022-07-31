#include<stdio.h>

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int i = 0;
  
  do {
    printf("%d ", arr[i]);

    i++;
  } while(i < 10);

  return 0;
}
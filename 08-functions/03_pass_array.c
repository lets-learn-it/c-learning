#include<stdio.h>

int sum1(int a[], int n);
int sum2(int* a, int n);

int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};

  printf("%d\n", sum1(arr, 10));

  printf("%d\n", sum2(arr, 10));

  return 0;
}

int sum1(int a[], int n) {
  int temp = 0;
  for(int i=0;i<n;i++)
    temp += a[i];
  return temp;
}

int sum2(int* a, int n) {
  int temp = 0;
  for(int i=0;i<n;i++) 
    temp += a[i];
  return temp;
}
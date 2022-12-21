#include <stdio.h>

void print1(const int * arr, int n) {
  for (int i=0;i<n;i++)
    printf("%d ", *(arr+i));
  printf("\n");

  // try to change value
  // This will give warning
  int *a = arr;
  *a = 34;
}

int main(int argc, char const *argv[]) {
  int arr[5] = {1,2,3,4,5};
  print1(arr, 5);
  print1(arr, 5);
  return 0;
}

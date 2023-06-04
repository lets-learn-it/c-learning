#include <stdio.h>

void pArray(int *arr, int n) {
  for (int i=0;i<n;i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble(int *arr, int n) {
  for (int i=0;i<n-1;i++) {
    for (int j=1;j<n-i;j++) {
      if (arr[j-1] > arr[j]) swap(&arr[j-1], &arr[j]);
    }
    pArray(arr, n);
  }
}

int main(int argc, char const *argv[]) {
  int arr1[] = {1,4,5,102,88,34,11,45,3,77,-66,555,76,78,-5 ,45,34};
  int n1 = sizeof(arr1)/sizeof(int);
  bubble(arr1, n1);

  printf("==================================\n");

  int arr2[] = {99, 98, 96, 95, 94, 93, 92, 91, 90};
  int n2 = sizeof(arr2)/sizeof(int);
  bubble(arr2, n2);
  return 0;
}

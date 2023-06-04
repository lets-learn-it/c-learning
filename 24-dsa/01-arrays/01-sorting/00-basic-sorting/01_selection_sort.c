#include <stdio.h>
#include <limits.h>

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

void selection(int *arr, int n) {
  int min_idx;
  for (int i=0;i<n-1;i++) {
    min_idx = i;
    for (int j=i+1;j<n;j++) {
      if (arr[min_idx] > arr[j]) min_idx = j;
    }
    swap(&arr[i], &arr[min_idx]);
    pArray(arr, n);
  }
}

int main(int argc, char const *argv[]) {
  int arr1[] = {1,4,5,102,88,34,11,45,3,77,-66,555,76,78,-5 ,45,34};
  int n1 = sizeof(arr1)/sizeof(int);
  selection(arr1, n1);

  printf("==================================\n");

  int arr2[] = {99, 98, 96, 95, 94, 93, 92, 91, 90};
  int n2 = sizeof(arr2)/sizeof(int);
  selection(arr2, n2);
  return 0;
}

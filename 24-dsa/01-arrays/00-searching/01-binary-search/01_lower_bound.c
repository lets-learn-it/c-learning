#include<stdio.h>

int lower_bound(int *arr, int n, int val) {
  if (arr[0] > val) return -1;

  int l = 0, r = n - 1;

  while(l <= r) {
    int mid = l + ((r - l) / 2);
    if (arr[mid] == val) return val;
    if (arr[mid] > val) r = mid - 1;
    else l = mid + 1;
  }
  return arr[r];
}

int main(int argc, char const *argv[]) {
  int arr1[] = {-1, -1, 2, 3, 5, 6};
  int n1 = sizeof(arr1) / sizeof(int);

  int arr2[] = {-1, -1, 3, 5, 6};
  int n2 = sizeof(arr2) / sizeof(int);

  int lb1 = lower_bound(arr1, n1, 4);
  printf("Lower bound: %d\n", lb1);

  int lb2 = lower_bound(arr2, n2, 4);
  printf("Lower bound: %d\n", lb2);
  return 0;
}

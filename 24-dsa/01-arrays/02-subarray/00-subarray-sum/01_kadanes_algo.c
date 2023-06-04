#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int max_subarray_sum(int *arr, int n) {
  int local_max = 0;
  int global_max = INT_MIN;

  for (int i=0; i<n; i++) {
    local_max = max(arr[i], arr[i] + local_max);
    if (local_max > global_max) global_max = local_max;
  }

  return global_max;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1,2,3,4-5,6,7,-4,33,-54,-6,44,32,1,-5,7};

  int n = sizeof(arr)/sizeof(int);

  int m = max_subarray_sum(arr, n);

  printf("Max subarray sum: %d", m);

  return 0;
}
#include <stdio.h>
#include <limits.h>

void build_prefix_array(int *arr, int *parr, int n) {
  parr[0] = arr[0];
  for(int i=1;i<n;i++) {
    parr[i] = parr[i-1] + arr[i];
  }
}

int max_subarray_sum(int *arr, int n) {
  int max_sum = arr[0];
  for (int i=0;i<n;i++) {
    for(int j=i;j<n;j++) {
      int subSum = i>0 ? arr[j] - arr[i-1] : arr[j];
      if (max_sum < subSum) max_sum = subSum;
    }
  }
  return max_sum;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1,2,3,4-5,6,7-4,33,-54,-6,44,32,1,-5,7};

  int n = sizeof(arr)/sizeof(int);

  int parr[n];

  build_prefix_array(arr, parr, n);

  int m = max_subarray_sum(parr, n);

  printf("Max subarray sum: %d", m);

  return 0;
}


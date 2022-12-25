#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int linear_search(int *arr, int n, int target) {

  for (int i=0;i<n;i++) {
    if (arr[i] == target) return i;
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  /////////////////////////////////////////////////////
  if (freopen("input.txt", "r", stdin) == NULL) return EXIT_FAILURE;
  if (freopen("output.gen.txt", "w", stdout) == NULL) return EXIT_FAILURE;
  clock_t start = clock();
  ////////////////// ACTUAL PROGRAM ///////////////////
  
  int t = 0, n = 0, target = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &target);

    int arr[n];

    for (int i=0;i<n;i++) {
      scanf("%d", &arr[i]);
    }

    printf("%d\n", linear_search(arr, n, target));
  }
  

  /////////////////////////////////////////////////////
  clock_t end = clock();
  fprintf(stderr, "Time: %f\n", (double) (end - start) / CLOCKS_PER_SEC);
  return 0;
}
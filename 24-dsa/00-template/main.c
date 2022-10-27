#include<stdio.h>

int main(int argc, char const *argv[]) {
  /////////////////////////////////////////////////////
  if (argc != 3) {
    printf("Provide input & output files...");
    return 1;
  }
  
  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);
  /////////////////////////////////////////////////////

  ////////////////// ACTUAL PROGRAM ///////////////////

  int t = 0, n = 0, total = 0, temp = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    total = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      total += temp;
    }
    printf("%d\n", total);
  }

  return 0;
}
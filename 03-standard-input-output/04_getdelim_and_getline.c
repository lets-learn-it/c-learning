#include<stdio.h>

#define printCharArray(arr, n) for(int i=0;i<n;i++) printf("%c", arr[i]);

int main() {
  char* line1 = NULL;

  // assigning value is IMP
  size_t len = 0;

  getdelim(&line1, &len, '\n', stdin);

  printCharArray(line1, len);

  fflush(stdin);
  char* line2 = NULL;

  getline(&line2, &len, stdin);

  printCharArray(line2, len);
  return 0;
}
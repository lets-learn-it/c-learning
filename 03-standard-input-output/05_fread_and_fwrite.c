#include<stdio.h>

/* 
  fread: Read chunks of generic data from STREAM.
  fwrite: Write chunks of generic data to STREAM.
 */

#define printCharArray(arr, n) for(int i=0;i<n;i++) printf("%c", arr[i]);

int main() {
  char s[20];

  /* 
    fread (void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream)
    __ptr: pointer to buffer where data will be available
    __size: size of each element (bytes)
    __n: number of elements
    stream: pointer to FILE object 

    Will read __size * __n bytes
   */
  fread(s, sizeof(char), 20, stdin);

  printCharArray(s, 20);

  printf("\n");

  /* 
    fwrite (const void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s)
   */

  fwrite(s, 1, 20, stdout);

  return 0;
}
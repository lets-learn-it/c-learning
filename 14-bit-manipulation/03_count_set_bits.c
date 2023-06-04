#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int n = 0b1100111010;
  int cnt, tmp;

  /* Count set bits */
  tmp = n;
  cnt = 0;
  while(tmp > 0) {
    cnt += tmp&1;
    tmp = tmp>>1;
  }
  printf("Total set bits in (%b): %d\n", n, cnt);

  /* Count set bits (efficient) */
  tmp = n;
  cnt = 0;
  while(tmp > 0) {
    // removes last set bit
    tmp= tmp&(tmp-1);
    cnt++;
  }
  printf("Total set bits in (%b): %d\n", n, cnt);
  
  return 0;
}

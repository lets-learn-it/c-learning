#define _GNU_SOURCE
#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i=0, n=10;

  #pragma omp parallel for
    for (i = 0;i <n;i++) {
      printf("%d\n", i);
    }

  return 0;
}
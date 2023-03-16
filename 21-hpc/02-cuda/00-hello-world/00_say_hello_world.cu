/* #include "cuda.h" */  // this is low level api
#include "cuda_runtime.h"

#include <stdio.h>

__global__ void hello_world() {
  printf("Hello World");
}

int main() {
  // <<<1,1>>> are kernel lauch parameters
  // this function is asynchronous (will not wait)
  // <<<number_of_blocks, threads_per_block>>>
  hello_world<<<1,1>>>();

  // wait for above operation to complete
  cudaDeviceSynchronize();

  // reset cuda devide / destroy CUDA context
  // All device allocations are removed.
  cudaDeviceReset();

  return 0;
}
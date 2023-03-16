#include "cuda_runtime.h"

#include <stdio.h>

__global__ void block_and_thread() {
  printf("blockIdx (%d, %d, %d) threadIdx (%d, %d, %d)\n", 
          blockIdx.x, blockIdx.y, blockIdx.z,
          threadIdx.x, threadIdx.y, threadIdx.z);
}

int main() {
  // dim3 (x, y, z)
  dim3 grid(3, 2, 1);  // total 6 blocks (grid of blocks)
  dim3 block(3);       // 3 threads per block (18 threads in total)
  block_and_thread<<<grid, block>>>();

  // wait for above operation to complete
  cudaDeviceSynchronize();

  // reset cuda devide
  cudaDeviceReset();

  return 0;
}
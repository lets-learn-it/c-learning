#include "cuda_runtime.h"
#include <stdio.h>

int main() {
  int device_id = 0; // select the first CUDA device
  cudaDeviceProp device_prop;
  cudaGetDeviceProperties(&device_prop, device_id);

  // Query the maximum number of blocks in each dimension
  printf("Maximum blocks per grid:\n");
  printf("x dimension: %d\n", device_prop.maxGridSize[0]);
  printf("y dimension: %d\n", device_prop.maxGridSize[1]);
  printf("z dimension: %d\n", device_prop.maxGridSize[2]);

  // Query the maximum number of threads per block in each dimension
  printf("Maximum threads per block:\n");
  printf("x dimension: %d\n", device_prop.maxThreadsDim[0]);
  printf("y dimension: %d\n", device_prop.maxThreadsDim[1]);
  printf("z dimension: %d\n", device_prop.maxThreadsDim[2]);

  return 0;
}
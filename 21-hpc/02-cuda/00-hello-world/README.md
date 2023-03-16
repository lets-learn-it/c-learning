# Hello World

## Blocks & Threads

- Consider blocks & threads are 3 dimentional structure. Each blocks has threads in it.
- Suppose we have grid of (3,3,1). mean we have total 3 blocks.
- suppose each block has (2,3,2) threads. means total 12 threads each block.
- So total no of threads will be 36.

### variables useful in kernel function

- `blockIdx.x, blockIdx.y, blockIdx.z`: id of block in grid
- `threadIdx.x, threadIdx.y, threadIdx.z`: id of thread in block
- `blockDim.x, blockDim.y, blockDim.z`: block dimension. Max threads in x, y, z direction resp. inside each block.
- `gridDim.x, gridDim.y, gridDim.z`: no of blocks in grid. Max blocks in x, y, z direction


## Limitations for number of blocks & threads per block

- size of block on x & y should not be more than 1024 and on z not more than 64.
- Total threads per block should not be more than 1024. i.e. (x * y * z) <= 1024
- no of blocks on y & z should not be more than 65536. while on x, it should be less than 2^32 - 1 (4,29,49,67,295).
- These limitations dependent on specific GPU model.& can be queried.





# Introduction

>OpenMP = Shared memory parallelism

OpenMP API uses **fork-join** model of parallel execution.

## Directive format

```c
#pragma omp directive-name [clause[ [,] clause]...] new-line
```

## Parallel Execution

```c
#pragma omp parallel
{
  // parallel region
}
```

Initial thread becomes **master thread** of team in `parallel` region with thread id equal to zero.

Any task within `parallel` region is allowed to encounter another `parallel` region to form nested `parallel` region. parallelism of nested `parallel` region (create new threads/execute sequentially) can be controlled by **`OMP_NESTED`** environment variable or **`omp_set_nested()`** API.

## Number of threads

- Using environment variable `OMP_NUM_THREADS`
- Using routine, `omp_set_num_threads(5)`
- Using `parallel` directive `num_threads(5)`
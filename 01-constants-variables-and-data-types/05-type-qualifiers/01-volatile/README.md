# volatile

- It tells compiler explicitly that the specified variable will change its value.
- compiler will suppress various kinds of optimizations.
- prevents compiler from caching variables. Useful with multithreading.
- only 3 types of variables should use volatile
  1. memory mapped peripheral registers
  2. global variables (non stack variables) modified by an interrupt service routine
  3. global variables accessed by multiple tasks within multi-threaded applications.

```c
// loc1 is volatile location
volatile int loc1;

// ploc points to volatile location
volatile int *ploc;
```
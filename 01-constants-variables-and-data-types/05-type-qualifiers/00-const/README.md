# const

- value of const will not be changed.
- compiler may give error if tried to change value of it.
  ```bash
  // gcc gives error
  assignment of read-only variable 'xxx'
  ```
- It allow compiler to place const variables into read-only memory

```c
// constant variable
const int a;

// pointer to constant
const int *a;
int const *a;

// constant pointer to variable
int *const a;

// both pointing to & pointer is constant
const int *const a;
```
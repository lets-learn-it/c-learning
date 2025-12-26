# Pointers

## Syntax

```c
float *p, **pp; // p is a pointer to float
                // pp is a pointer to a pointer to float
int (*fp)(int); // fp is a pointer to function with type int(int)

// const with pointers
int n;
const int * pc = &n; // pc is a non-const pointer to a const int
// *pc = 2; // Error: n cannot be changed through pc without a cast
pc = NULL; // OK: pc itself can be changed

int * const cp = &n; // cp is a const pointer to a non-const int
*cp = 2; // OK to change n through cp
// cp = NULL; // Error: cp itself cannot be changed

int * const * pcp = &cp; // non-const pointer to const pointer to non-const int
```

> `const` applies to what is immediately on its left; if there is nothing on the left, it applies to what is on its right.

- `const int *p`
- `int const *p`
- `int * const p`

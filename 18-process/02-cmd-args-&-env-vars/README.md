# Cmd args & Env Vars

## Cmd Args

```c
int main(int argc, char *argv[])

// argc has number of args
// argv has those args
```

>Note: `argc[argc]` is null pointer

## Environment Vars

- Environment list is array of character pointers, with each pointer containing address of null terminated `\0` C string.
- Address of array of pointers is contained in global variable `environ`
  ```c
  extern char **environ;
  ```
- Access to specific environment variable is normally through the `getenv` and `putenv` functions instead of `environ`.

```c
#include <stdlib.h>

// returns null if not found
char *getenv(const char *name);

int putenv(char *str);

int setenv(const char *name, const char *value, int rewrite);

int unsetenv(const char *name);
```
# popen & pclose

These functions are provided by standard library. They work only in one direction (either read from child's stdout or write to child's stdin). This is because popen creates one pipe and pipes are basically unidirectional.

```c
#include <stdio.h>

// returns file pointer if OK else null
FILE *popen(const char *cmdstring, const char *type);

// returns return code of cmdstring or -1 on error
int pclose(FILE *fp);
```

function `popen()` does `fork` and `exec`
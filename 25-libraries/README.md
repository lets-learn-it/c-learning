# Libraries

## Static Libraries

- Static libraries are compiled into the final executable file of a program. (library is included into final executable)
- These are self contained & do not require additional files but this makes final executable size larger.
- another disadvantage of static libraries is "these can be loaded separately by different applications"
- static libraries are preferred when the library code is not expected to change.

```sh
# compile program
gcc -c mylib.c -o mylib.o

# create library
ar rcs libmylib.a mylib.o

# use library (link)
gcc myprogram -lmylib -o myprogram.exe

# or lib is directory where lib present
gcc myprogram -Llib -lmylib -o myprogram.exe
```

## Dynamic Libraries

- Dynamic libraries are compiled into separate files that are not included in the final executable of a program. but they are loaded into memory at runtime when the program needs to use them.
- These libraries can be shared between different applications. Which saves storage & memory both.
- These libraries can be updated without compiling applications.
- dynamic libraries are preferred when the library code is expected to change or be updated.

```sh
# compile program
# "-fPIC" flag is used to create position-independent code
gcc -c -fPIC mylib.c -o mylib.o

# create library
gcc -shared mylib.o -o libmylib.so

# use library (link)
gcc myprogram -lmylib -o myprogram.exe

# or lib is directory where lib present
gcc myprogram -Llib -lmylib -o myprogram.exe
```

>Note: dynamic libraries may have different file extensions on different systems. `.dll` for windows while `.so` for linux

While running program, system should know about location of shared library which can be specified by

```sh
# in linux
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/lib

# or
gcc -Wl,-rpath=/path/to/lib main.c -o main -lmylib

# in mac os
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/path/to/lib

# in windows, its PATH variable
```

### Useful tools for working with Shared Libraries

#### ldd

#### objdump

#### nm

## References

[[01] https://stackoverflow.com/questions/140061/when-to-use-dynamic-vs-static-libraries](https://stackoverflow.com/questions/140061/when-to-use-dynamic-vs-static-libraries)

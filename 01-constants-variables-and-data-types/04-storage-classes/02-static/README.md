# static keyword

It is completely opposite to `extern`. A static function/variable in C is a function that has a scope that is limited to its object file.

```sh
# compile only
gcc -c main.c static.c

# now link also
gcc main.o static.o
```

**ERRORS**

```
undefined reference to `age'
```

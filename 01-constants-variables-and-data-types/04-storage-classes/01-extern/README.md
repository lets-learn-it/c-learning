# extern and global variables

> The keyword `extern` means "the storage for this variable is allocated elsewhere". It tells the compiler "I'm referencing _myGlobalvar_ here, and you haven't seen it before, but that's OK; the linker will know what you are talking about."

```shell
gcc global.c main.c
```

## References

[[0] https://stackoverflow.com/a/2652576/8507296](https://stackoverflow.com/a/2652576/8507296)

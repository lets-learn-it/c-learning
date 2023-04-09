# POSIX memory

- POSIX provide multiple ways to allocate, deallocate, limit virtual memory of process (address space).
- `brk()` and `sbrk()` change the location of the program break, which defines the end of the process's data segment (i.e., the program break is the first location after the end of the uninitialized data segment).  **Increasing the program break has the effect of allocating memory to the process; decreasing the break deallocates memory.**
- `mmap`, `munmap` can be used to allocated/deallocate memory for process other than its many usages. Below flags are important.
  - `MAP_ANON`: Synonym for `MAP_ANONYMOUS`; provided for compatibility with other implementations.
  - `MAP_ANONYMOUS`: **The mapping is not backed by any file; its contents are initialized to zero.**  The fd argument is ignored; however, some implementations require fd to be -1 if `MAP_ANONYMOUS` (or `MAP_ANON`) is specified, and portable applications should ensure this.  The offset argument should be zero. The use of `MAP_ANONYMOUS` in conjunction with `MAP_SHARED` is supported on Linux only since kernel 2.4.
- The `getrlimit()` and `setrlimit()` system calls get and set resource limits.  Each resource has an associated soft and hard limit, as defined by the rlimit structure:
  ```c
  struct rlimit {
    rlim_t rlim_cur;  /* Soft limit */
    rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
  };
  ```
  **The soft limit is the value that the kernel enforces for the corresponding resource.**  The hard limit acts as a ceiling for the soft limit: an **unprivileged process may set only its soft limit to a value in the range from 0 up to the hard limit, and (irreversibly) lower its hard limit.**  A privileged process (under Linux: one with the `CAP_SYS_RESOURCE` capability in the initial user namespace) may make arbitrary changes to either limit value.

  The value `RLIM_INFINITY` (it is -1) denotes no limit on a resource (both in the structure returned by `getrlimit()` and in the structure passed to `setrlimit()`)


## References

[[00] https://man7.org/linux/man-pages/man2/getrlimit.2.html](https://man7.org/linux/man-pages/man2/getrlimit.2.html)

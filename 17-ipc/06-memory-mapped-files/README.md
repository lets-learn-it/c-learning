# Memory Mapped Files

- memory of region corresponds to a traditional file on disk.
- no need of `read()`, `write()` or `fseek()` because file is already in memory.
- Memory-mapped files allow for multiple processes to share read-only access to a common file. As a straightforward example, the C standard library (glibc.so) is mapped into all processes running C programs.
- when we use `read()` with file, kernel copies data from disk to kernel's **buffer cache** and then copies to process's user mode memory. But memory mapped files bypass buffer cache & copies directly into user mode portion of memory.
- If shared region is writable, memory mapped files provide extremely fast IPC data exchange.
  >Setting up regions in both processes is expensive operation in terms of execution time.
- memory mapped files create persistent IPC. in case of pipes, message wont be available when any process reads it.

## C library functions

```c
// map a file by fd into memory at address addr
// prot is protection. discussed below
void *mmap (void *addr, size_t length, int prot, int flags, int fd, off_t offset);

// Unmap a mapped region.
int munmap (void *addr, size_t length);

// Synchronize mapped region with its underlying file.
int msync (void *addr, size_t length, int flags);
```

## Regio protections and privacy

>These protections **only apply to the current process**. If another process maps the same file into its virtual memory space, that second process may set different protections. As such, it is possible that a region marked as read-only in one process may actually change while the process is running.

| **Protection** | **Actions Permitted**                  |
|----------------|----------------------------------------|
| **PROT_NONE**  | The region may not be accessed         |
| **PROT_READ**  | The contents of region can be read     |
| **PROT_WRITE** | The contents of region can be modified |
| **PROT_EXEC**  | The contents of region can be executed |

**Privacy**

In `flags` parameter, region can be designated as private (`MAP_PRIVATE`) or shared (`MAP_SHARED`). exactly one flag is required while calling `mmap()`. In addition to these flags, there are multiple falgs available https://man7.org/linux/man-pages/man2/mmap.2.html

## Mapping

A file is mapped in multiples of the page size.  For a file that is not a multiple of the page size, the remaining bytes in the partial page at the end of the mapping are zeroed when mapped, and modifications to that region are not written out to the file.

## References

[[1] https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/MMap.html](https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/MMap.html)
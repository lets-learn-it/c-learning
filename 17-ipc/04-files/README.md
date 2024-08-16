# Files

files can be used for IPC by locking mechanism.
- **Mandatory locking**: It will prevent `read()` and `write()` to file.
- **Advisory locking**: processes can still read and write from file while it's locked. Process has to check if file is locked or not.

## Mandatory Locking

[https://stackoverflow.com/questions/77931997/linux-mandatory-locking-for-file-locking](https://stackoverflow.com/questions/77931997/linux-mandatory-locking-for-file-locking)

## Advisory Locking

- process can lock file for reading or writing. Multiple processes can lock for reading at same time.
- When process lock file for writing, no other process can lock for reading or writing.
- for locking, we can use either `flock()` or `fcntl()`.

### Lock/Unlock file

```c
#include <fcntl.h>
struct flock fl = {
  .l_type = F_WRLCK,    /* F_RDLCK, F_WRLCK, F_UNLCK */
  .l_whence = SEEK_SET, /* SEEK_SET, SEEK_CUR, SEEK_END */
  .l_start = 0,         /* Offset from l_whence */
  .l_len = 0,           /* length, 0 mean whole file */
  // .l_pid             /* PID holding lock, F_RDLCK only. set bu kernel */
};

int fd = open("./file.txt", O_WRONLY);

// lock file
fcntl(fd, F_SETLKW, &fl);   /* F_GETLK, F_SETLK, F_SETLKW */

// unlock same region of file
fl.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &fl);
```

> when you open the file, you need to open it in the same mode as you have specified in the lock. If you open the file in the wrong mode for a given lock type, `fcntl()` will return `-1` and `errno` will be set to `EBADF`.

### Check if file locked

```c
struct flock fl = { 0 };

int fd = open("../file.txt", O_WRONLY);
fcntl(fd, F_GETLK, &fl);   /* F_GETLK, F_SETLK, F_SETLKW */

if (fl.l_type == F_WRLCK) {
  printf("file is locked by process %d\n", fl.l_pid);
} else {
  printf("file not locked.\n");
}
```
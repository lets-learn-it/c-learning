# seccomp

## Install Dev & Run Program

```sh
sudo apt install libseccomp-dev

# run
gcc main.c  -lseccomp
./a.out
```

## default actions

- `SCMP_ACT_KILL_PROCESS`: kill process
- `SCMP_ACT_KILL_THREAD` / `SCMP_ACT_KILL`: kill thread
- `SCMP_ACT_TRAP`: Throw a SIGSYS signal
- `SCMP_ACT_NOTIFY`: Notifies userspace
- `SCMP_ACT_ERRNO(x)`: Return the specified error code
- `SCMP_ACT_TRACE(x)`: Notify a tracing process with the specified value
- `SCMP_ACT_LOG`: Allow the syscall to be executed after the action has been logged
- `SCMP_ACT_ALLOW`: Allow the syscall to be executed
- `SECCOMP_RET_USER_NOTIF`: > v5.0

## References

[[00] https://filippo.io/linux-syscall-table/](https://filippo.io/linux-syscall-table/)

[[01] https://github.com/cloudflare/sandbox](https://github.com/cloudflare/sandbox)

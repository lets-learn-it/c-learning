# Namespace

- It provide a way to isolate and virtualize system resources, such as process IDs, network interfaces, and file systems, so that a process can have its own independent view of those resources.

## Namespace Types

- `CLONE_NEWCGROUP`: isolates cgroup root directory
- `CLONE_NEWIPC`: isolates system v IPC, POSIX message queues
- `CLONE_NEWNET`: isolates network devices, stacks, ports etc.
- `CLONE_NEWNS`: isolates mount points
- `CLONE_NEWPID`: isolates process ids
- `CLONE_NEWTIME`: isolates boot & monotonic clocks
- `CLONE_NEWUSER`: isolates user & group ids
- `CLONE_NEWUTS`: isolates hostname & NIS (Network information service) domain name

## System Calls

- `clone`: it create new process. While creating, one or more flags can added (`CLONE_NEW*`). It will create new namespaces & put new process in them.
- `setns`: calling process can join existing namespace. namespace to join is specified via file descriptor that refers to one of the `/proc/[pid]/ns` files.
- `unshare`: moves calling process to new namespace. same as clone, just without creating new process.
- `ioctl`: 

> for creating new namespace using `clone` and `unshare`, `CAP_SYS_ADMIN` capability required except in case of user namespace.

## Namespaces for process

- each process has `/proc/[pid]/ns/` subdirectory containing one entry for each namespace.
- If two processes are in the same namespace, then the device IDs and inode numbers of their `/proc/[pid]/ns/xxx` symbolic links will be the same; an application can check this using the `stat.st_dev` and `stat.st_ino` fields returned by `stat`.
- `/proc/sys/user/xxx` exposes limits on number of namespaces of variours types that can be created.
- namespace is automatically torn down when last process in namespace terminates or leaves namespace. except,
  - open file descriptor or a bind mount exists for corresponing `/proc/[pid]/ns/*` file.
  - namespace is hierarchical (pid/user) and has child namespace.
  - it is user namespace that owns other nonuser namespace.
  - it is pid namespace and there is process that refers to the namespace via `/proc/[pid]/ns/pid_for_children` symbolic link.
  - it is time namespace, and there is process that refers to the namespace via `/proc/[pid]/ns/time_for_children` symbolic link.
  - it is IPC namespace, and corresponding mount of `mqueue` filesystem refers to this namespace.
  - it is PID namespace and correspoinding mount of `proc` filesystem refers to this namespace.

## References

[[00] https://man7.org/linux/man-pages/man7/namespaces.7.html](https://man7.org/linux/man-pages/man7/namespaces.7.html) 

[[01] https://man7.org/linux/man-pages/man2/ioctl_ns.2.html](https://man7.org/linux/man-pages/man2/ioctl_ns.2.html)

# Joinable Vs Detached

## Joinable

```c
int pthread_join(pthread_t thread, void **retval);
```

Above function waits for the thread specified by thread to terminate. If that thread has already terminated, then pthread_join() returns immediately.  The thread specified by thread must be joinable (should not be already detached).

All of the threads in a process are peers: any thread can join with any other thread in the process.

## Detached

```c
int pthread_detach(pthread_t thread);
```

Above function marks the thread identified by thread as detached.  When a detached thread terminates, its **resources are automatically released back to the system** without the need for another thread to join with the terminated thread.

Once a thread has been detached, it can't be joined with `pthread_join()` or be made joinable again.

A new thread can be created in a detached state using `pthread_attr_setdetachstate(3)` to set the detached attribute of the attr argument of `pthread_create(3)`.

>**Note**: Either `pthread_join(3)` or `pthread_detach()` should be called for each thread that an application creates, so that **system resources for the thread can be released**.  (But note that the resources of any threads for which one of these actions has not been done will be **freed when the process terminates.**)

## References

[[01] https://man7.org/linux/man-pages/man3/pthread_detach.3.html](https://man7.org/linux/man-pages/man3/pthread_detach.3.html)
[[02] https://man7.org/linux/man-pages/man3/pthread_join.3.html](https://man7.org/linux/man-pages/man3/pthread_join.3.html)

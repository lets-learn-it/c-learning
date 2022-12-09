# Pipes

- pipes are **unidirectional**
- pipes are **order preserving**
- pipes have **limited capacity** and they use **blocking I/O**. If a pipe is full, any additional writes to the pipe will block the process until some of the data has been read.
- pipes send data as **unstructured byte streams**.
- Messages that are smaller than the size specified by `PIPE_BUF` are guaranteed to be sent **atomically**. As such, if two processes write to a pipe at the same time, both messages will be written correctly and they will not interfere with each other.

>It is very important to **close the unused end of the pipe** immediately after the fork(). Failure to do so can cause programs to freeze unexpectedly. 
 <br>**Example**: parent process will try to read from the pipe. Instead of immediately returning, the process will block until an EOF (end-of-file) is written into the pipe. Since the child is the only other process that could write to the pipe and the child exits without writing anything, the parent will block indefinitely.

## Named Pipes / FIFO

Above pipes (anonymous pipes) can't be used for unrelated processes. Specifically, the call to `pipe()` must happen within the same program that later calls `fork()`.

FIFOs work by attaching a filename to the pipe thats why **named pipes**.

Also similar to anonymous pipes, **FIFOs use blocking I/O until both ends are opened by at least one process.**. For using non blocking fifo, pass the `O_NONBLOCK`option during the call to `open()` to make the FIFO access non-blocking.

### Creating FIFO

- use `mkfifo()` to create fifo
- other process can access fifo by calling `open()` on associated filename. (should have permissions)

## References

[[1] https://tldp.org/LDP/lpg/node11.html](https://tldp.org/LDP/lpg/node11.html)
[[2] https://www.linuxjournal.com/article/2156](https://www.linuxjournal.com/article/2156)
[[3] https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/Pipes.html](https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/Pipes.html)
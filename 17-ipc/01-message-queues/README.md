# Message Queues

## POSIX message queues

- for processes to communicate by exchanging **structured messages.**
- When a message is retrieved from the queue, the process receives exactly one message in its entirety; there is no way to retrieve part of a message and leave the rest in the queue.
- message queues are special identifiers and not file descriptors.
- message queues **do not require or guarantee a first-in, first-out ordering**. depends on *priority.*
- Message queues have kernel-level persistence and use special functions or utilities for removing them. **Killing the process will not remove the message queue.**
- POSIX message queue is **only removed once it is closed by all processes** currently using it.
- message queues has asynchronous notification feature means reader do not wait for message
- can add attributes to queue like message size or capacity of queue.

### Steps

```c
// Open (and possibly create) a POSIX message queue.
mqd_t mq_open (const char *name, int oflag, ... /* mode_t mode, struct mq_attr *attr */);

// Get the attributes associated with a given message queue.
int mq_getattr(mqd_t mqdes, struct mq_attr *attr);

// Close a message queue.
int mq_close (mqd_t mqdes);

// Initiate deletion of a message queue.
int mq_unlink (const char *name);

// Send the message pointed to by msg_ptr with priority msg_prio.
int mq_send (mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);

// Receive a message into a buffer pointed to by msg_ptr and get its priority msg_prio. 
ssize_t mq_receive (mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
```

### Asynchronous MQ

- by default, if queue is full, writer will block and if no messages available, reader will block
- We can use `O_NONBLOCK` while opening queue in `oflag` bit mask. which will **return error instead of blocking.**
- Or we can use `mq_timedsend()` and `mq_timedreceive()` which takes parameter `abs_timeout`. It will block read/write till `abs_timeout`
- Most useful way is using `mq_notify()`. it can be used for requesting asynchronous notification when message is sent.

## References

[[1] https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/MQueues.html](https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/MQueues.html)
# inotify

## Steps

- use `inotify_init()` to create *inotify instance*. System will return file descriptor.
- use `inotify_add_watch()` for adding files (watchlist items) of interest. Each item consists of **pathname** and associated **bit mask (events)**. returns *watch descriptor*

  ```c
  // returns non negative watch descritor
  // if pathname not exist in inotify instance, then will be added
  // if it is already exists then it will be modified.
  inotify_add_watch(int fd, const char *pathname, uint32_t mask);
  ```
  Caller should have **read permission** for pathname file.
- added watch can also be removed using `inotify_rm_watch(int fd, uint32_t wd)`. removing watch descriptor will generated `IN_IGNORED` event.
- To get event notifications, perform `read()` operations on inotify file descriptor. **Each successful read returns one or more `inotify_event` structures**.
- when done watching, close inotify file descriptor.

>**Note**: when monitoring directory, you will get events for directory as will as files. And it will not monitor other directories inside that directory.

These inotify monitoring file descriptors can be monitored using `select()`, `poll()`, `epoll()` etc.

## Events

- `IN_ACCESS`: File was accessed `read()`
- `IN_ATTRIB`: File metadata changed
- `IN_CLOSE_WRITE`: File opened for writing was closed
- `IN_CLOSE_NOWRITE`: File opened read-only was closed
- `IN_CREATE`: file/directory created inside watched directory
- `IN_DELETE`: file/directory deleted from watched directory
- `IN_DELETE_SELF`: watched file/directory was deleted
- `IN_MODIFY`: file was modified
- `IN_MOVE_SELF`: watched file/directory was moved
- `IN_MOVED_FROM`: file moved out of watched directory
- `IN_MOVED_TO`: file moved into watched directory
- `IN_OPEN`: file was opened

## References

https://www.linuxjournal.com/article/8478
https://developer.ibm.com/tutorials/l-ubuntu-inotify/
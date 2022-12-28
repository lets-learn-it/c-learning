# Hello Netlink

## Linux Kernel Module

**Kernel module steps**

- Register init & cleanup functions
- Initialization `struct netlink_kernel_cfg`
- netlink socket creation
- receiving user space message
- processing userspace message
- replying to user space
- netlink socket destruction

**User space program steps**

- create userspace netlink socket
- start separate netlink msg receive thread



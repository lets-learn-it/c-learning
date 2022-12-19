# Threading

### Threads within same process share

- Address Space
- Process Instructions
- Most data
- Open files (descriptors)
- Signals & Signal Handlers
- Current Working Directory
- User & group id

### Threads has unique

- Thread id
- set of registers, stack pointers
- stack for local variables, return addresses
- signal mask
- priority
- return value `errno`
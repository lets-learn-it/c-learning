# IPC

| **Technique**          | **Model**       | **Purpose**     | **Granularity** | **Network** |
|------------------------|-----------------|-----------------|-----------------|-------------|
| **pipe/FIFO**          | message passing | data exchange   | byte stream     | local       |
| **socket**             | message passing | data exchange   | either          | either      |
| **message queue**      | message passing | data exchange   | structured      | local       |
| **shm()**              | shared memory   | data exchange   | none            | local       |
| **memory mapped file** | shared memory   | data exchange   | none            | local       |
| **signal**             | message passing | synchronization | none            | local       |
| **semaphore**          | message passing | synchronization | none            | local       |
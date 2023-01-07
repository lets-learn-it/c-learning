# Modules

## Loadable Module

###  Loadable Modules Vs Static Modules

#### Static Module

- Linked to kernel image (vmlinuz file). can be found in `/boot` directory.
- Loaded as part of kernel at boot time & available to use during booting.
- When module changes, we have to reconfigure, rebuild, reboot to change

### Dynamic / Loadable Module

- Loadable kernel modules (LKM)
- file extension is `.ko`
- designed to be loaded after the kernel has booted.
- without rebooting, we can edit, rebuild, and reload module

### When modules can't be loadable

- Need it at boot time
- eg. support for the first file system. Initial RAM file system support is needed.

## Module Commands (Linux)

- **`insmod`**: 
  - loading new module. (`.ko` file).
  - Privileged command.
  - Requires its *dependencies* to already be loaded.
  - Some modules can be found `/lib/modules/$(uname -r)/kernel/fs`.
- **`rmmod`**:
  - removing already loaded module (no need to add `.ko`).
  - Privileged command.
- **`lsmod`**:
  - Lists loaded modules.
  - Info from `/proc` and `/sys/modules/*`.
  - Does not list statically linked modules.
  - Gives module name, size, used count & used by modules
- **`depmod`**:
  - processes dependency information (one module dependent on another)
  - generates `modules.dep[.bin]` and map files.
  - dep file `/lib/modules/$(uname -r)/modules.dep`
  ```sh
  cd /lib/modules/$(uname -r)

  # Check entry for btrfs module
  grep btrfs.ko modules.dep
  ```
- **`modprobe`**
  - Uses dependency file to load dependencies first & then module
  - Don't provide path, create module name
- **`modinfo`**
  - Prints info about modules
  - extracts info from module file (`.ko`)
  - file name or module name


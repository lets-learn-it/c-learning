# Hello Device

### Build & Load Driver

```sh
# build
make

# load
sudo insmod helloWorldLKM.ko

# list loaded modules
lsmod

# check logs
tail -f /var/log/kern.log

# unload
sudo rmmod helloWorldLKM
```

## Driver

```sh
# check driver registered for device
cat /proc/devices

# Create Device Entry
sudo mknod -m <permissions> /dev/<name> <c/b> <major> <minor>
sudo mknod -m 666 /dev/hello_device c 222 0
```

## References

[[00] Youtube - Linux Device Drivers Training 06, Simple Character Driver (Karthik M)](https://www.youtube.com/watch?v=E_xrzGlHbac)
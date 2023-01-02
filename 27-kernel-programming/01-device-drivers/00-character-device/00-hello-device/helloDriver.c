#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> /* For the character driver support */
#include <linux/string.h>

static char buf[] = "I am Character Device!!!";

ssize_t device_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset) {
  int bytes_to_copy = 0;

  printk(KERN_INFO "Inside the %s function\n", __FUNCTION__);

  bytes_to_copy = strlen(buf) < length ? strlen(buf) : length;

  if (copy_to_user(buffer, &buf, bytes_to_copy) != 0) { /* dont care about offset */
    printk(KERN_ERR "Error in copy_to_user\n");
    return 0;
  }

  printk(KERN_INFO "bytes copied %d\n", bytes_to_copy);

  return bytes_to_copy;
}

ssize_t device_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset) {
  printk(KERN_INFO "Inside the %s function\n", __FUNCTION__);
  return length; /* return successful */
}

int device_open (struct inode *pinode, struct file *pfile) {
  printk(KERN_INFO "Inside the %s function\n", __FUNCTION__);
  return 0;
}

int device_release (struct inode *pinode, struct file *pfile) {
  printk(KERN_INFO "Inside the %s function\n", __FUNCTION__);

  return 0;
}

/* file_operations structure to register driver operations */
struct file_operations device_file_operations = {
  .owner = THIS_MODULE,
  .open = device_open,
  .read = device_read,
  .write = device_write,
  .release = device_release
};

int hello_device_init_module(void) {
  printk(KERN_INFO "Hello Device! Driver loaded successfully.\n");

  /* Register character device driver with kernel */
  register_chrdev(222 /* major number (make sure no device already registered */,
                  "Simple Char Drv" /* Name of Driver */,
                  &device_file_operations /* File operations structure */);
  return 0;
}

void hello_device_cleanup_module(void) {
  printk(KERN_INFO "Goodbye Device \n");

  /* unregister device */
  unregister_chrdev(222, "Simple Char Drv");
}

module_init(hello_device_init_module);
module_exit(hello_device_cleanup_module);

#define AUTHOR_NAME "Parikshit_Patil"
#define MODULE_DESC "Hello_device_driver"

MODULE_AUTHOR(AUTHOR_NAME);
MODULE_DESCRIPTION(MODULE_DESC);
MODULE_LICENSE("GPL");

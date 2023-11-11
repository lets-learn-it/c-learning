#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> /* For the character driver support */
#include <linux/string.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define MAJOR_NUM 222
#define DRIVER_NAME "driverWithDevice"
#define DRIVER_CLASS "driverWithDeviceClass"

/* buffer for data */
static char buffer[255];
static int buffer_pointer;

/*  variables for device & device class */
static dev_t my_device_nr;
static struct class *my_class;
static struct cdev my_device;

static ssize_t device_read (struct file *File, char *user_buffer, size_t count, loff_t *offs) {
  int to_copy, not_copied, delta;

  /* Get Amount of data to copy */
  to_copy = min(count, buffer_pointer);

  /* Copy data to user */
  not_copied = copy_to_user(user_buffer, buffer, to_copy);

  /* calculate data */
  delta = to_copy - not_copied;

  return delta;
}

static ssize_t device_write (struct file *File, const char *user_buffer, size_t count, loff_t *offs) {
  int to_copy, not_copied, delta;

  /* Get Amount of data to copy */
  to_copy = min(count, sizeof(buffer));

  /* Copy data to user */
  not_copied = copy_from_user(buffer, user_buffer, to_copy);
  buffer_pointer = to_copy;

  /* calculate data */
  delta = to_copy - not_copied;

  return delta;
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

  /* create device file */
  if ( alloc_chrdev_region(&my_device_nr, 0, 1, DRIVER_NAME) < 0) {
    printk("device could not be allocated\n");
    return -1;
  }

  printk("Device allocated. Major: %d, Minor: %d\n", my_device_nr >> 20, my_device_nr && 0xfffff);

  /* create device class */
  if ((my_class = class_create(THIS_MODULE, DRIVER_CLASS)) == NULL) {
    printk("can not create device file\n");
    goto FileError;
  }

  /* create device file */
  if (device_create(my_class, NULL, my_device_nr, NULL, DRIVER_NAME) == NULL) {
    printk("can not create device file.\n");
    goto ClassError;
  }
  /* initialize device file */
  cdev_init(&my_device, &device_file_operations);

  /* registering device to kernel */
  if (cdev_add(&my_device, my_device_nr, 1) == -1) {
    printk("Registering of device to kernel failed.\n");
    goto AddError;
  }

  return 0;

AddError:
  device_destroy(my_class, my_device_nr);
  
FileError:
  class_destroy(my_class);

ClassError:
  unregister_chrdev_region(my_device_nr, 1);
  return -1;
}

void hello_device_cleanup_module(void) {
  printk(KERN_INFO "Goodbye Device \n");

  cdev_del(&my_device);
  device_destroy(my_class, my_device_nr);
  class_destroy(my_class);
  unregister_chrdev_region(my_device_nr, 1);
  printk("Exited successfully.\n");
}

module_init(hello_device_init_module);
module_exit(hello_device_cleanup_module);

#define AUTHOR_NAME "Parikshit_Patil"
#define MODULE_DESC "Hello_device_driver"

MODULE_AUTHOR(AUTHOR_NAME);
MODULE_DESCRIPTION(MODULE_DESC);
MODULE_LICENSE("GPL");


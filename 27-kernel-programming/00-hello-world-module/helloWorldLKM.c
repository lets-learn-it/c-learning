#include <linux/module.h>
#include <linux/kernel.h>

int hello_world_init_module(void) {
  printk(KERN_INFO "Hello World! Module loaded successfully.\n");
  return 0;
}

void hello_world_cleanup_module(void) {
  printk(KERN_INFO "Goodbye world \n");
}

module_init(hello_world_init_module);
module_exit(hello_world_cleanup_module);

#define AUTHOR_NAME "Parikshit_Patil"
#define MODULE_DESC "Hello_world_module"

MODULE_AUTHOR(AUTHOR_NAME);
MODULE_DESCRIPTION(MODULE_DESC);
MODULE_LICENSE("GPL");

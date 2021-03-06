#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yango3");

static int __init hello_init(void) {
    printk(KERN_ALERT "(init)Hello,world!\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_ALERT "(exit)Hello,world!\n");
}

module_init(hello_init);
module_exit(hello_exit);


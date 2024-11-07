#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/printk.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/gpio.h>
#include <asm-generic/uaccess.h>
#include <mach/gpio.h>

#define S_N 0
#define N_D 2
#define DRIVER_NAME "LED1 driver"

#define LED1 S5PV210_GPJ2(0)
#define LED_ON 0
#define LED_OFF 1


static dev_t mydevno;

int myopen(struct inode* inodep, struct file *fp) {
    printk("Driver " DRIVER_NAME " opened.\n");
    return 0;
}

int mywrite(struct file *fp, const char __user *buf, size_t count, loff_t *position) {
    char led_status;
    int ret;
    ret = copy_from_user(&led_status, buf, 1);
    if (ret) {
        printk("Fail to copy data from the user space to the kernel space!\n");
    }
    if (led_status == '1') {
        gpio_set_value(LED1, LED_ON);
    } else {
        gpio_set_value(LED1, LED_OFF);
    }
    return 1;
}

int myclose(struct inode* inodep, struct file *fp) {
    printk("Driver " DRIVER_NAME " closed.\n");
    return 0;
}

struct file_operations myfops = {
    owner: THIS_MODULE, 
    open: myopen, 
    write: mywrite, 
    release: myclose, 
};

struct cdev mydev; 

static int __init led1_init(void) {
    int ret;
    unsigned int major, minor;
    // register a major number
    ret = alloc_chrdev_region(&mydevno, S_N, N_D, DRIVER_NAME);
    if (ret < 0) {
        printk("alloc_chrdev_region failed. Driver " DRIVER_NAME " cannot get major number.\n");
        return ret;
    }
    major = MAJOR(mydevno);
    minor = MINOR(mydevno);
    printk("Driver " DRIVER_NAME " initialized (major number = %d, minor number = %d).\n", major, minor);
    // register a char device 
    cdev_init(&mydev, &myfops);
    mydev.owner = THIS_MODULE;
    ret = cdev_add(&mydev, mydevno, N_D);
    if (ret) {
        printk("Driver " DRIVER_NAME " register fail.\n");
        return ret;
    }
    return 0;
    
}

static void __exit led1_exit(void) {
    cdev_del(&mydev);
    unregister_chrdev_region(mydevno, N_D);
    printk("Driver " DRIVER_NAME " unloaded.\n");
}

module_init(led1_init);
module_exit(led1_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qixin Wang");
MODULE_DESCRIPTION("LED1 Char Driver");


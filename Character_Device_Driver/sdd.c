#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h> /* For the character driver support */

int ex01_open (struct inode *pinode, struct file *pfile)
{	
	printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
	return 0;

}	

ssize_t ex01_read (struct file *pfile, char __user *buffer, size_t length , loff_t *offset)
{
		printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
		return 0;

}

ssize_t ex01_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
		printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
		return length;

}

int ex01_close (struct inode *pinode, struct file *pfile)
{
		printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);
		return 0;

}

/* To hold the file opeartions performed on this device */

struct file_operations ex01_file_operations = { 
	.owner = THIS_MODULE,
	.open = ex01_open,
	.read = ex01_read,
	.write = ex01_write,
	.release = ex01_close,
};




int ex01_sdd_module_init(void)
{
	printk(KERN_ALERT "Inside the %s function \n", __FUNCTION__);

	/* Register with the kernel and indicate that we are registering a character device driver */
	register_chrdev(240 /* Major Number */ ,"Simple Char Drv" /* Name of the driver */ , &ex01_file_operations /* File Operations */);
	return 0;
}

void ex01_sdd_module_exit(void)
{
	printk(KERN_ALERT "INside the %s function \n", __FUNCTION__);
	/*Unregister the character device driver*/
	unregister_chrdev(240,"Simple Char Drv");
}
MODULE_LICENSE("GPL");
module_init(ex01_sdd_module_init);
module_exit(ex01_sdd_module_exit);

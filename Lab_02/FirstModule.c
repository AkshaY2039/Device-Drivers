/*
	Source Code
	Compilig Requires Linux Headers
		sudo apt-get update
		sudo apt-get install linux-headers-$(uname -r)
*/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/delay.h>

static int __init init_mod (void) /*Constructor*/
{
	printk (KERN_INFO "First Module Started ...\n");
	int x = 10;
	while (x)
	{
		msleep (500);
		printk (KERN_INFO "First Module Active ...%d\n", x--);
	}
	return 0;
}

static void __exit end_mod (void) /*Destructor*/
{
	printk (KERN_INFO "First Module Ended ...\n");
}

module_init (init_mod);
module_exit (end_mod);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Akshay Kumar");
MODULE_DESCRIPTION ("Printing Active every 0.5 seconds for 10 times");
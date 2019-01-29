/*
	Source Code
	Compilig Requires Linux Headers
		sudo apt-get update
		sudo apt-get install linux-headers-$(uname -r)
*/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>

static int __init init_mod (void) /*Constructor*/
{
	printk (KERN_INFO "Module1 Started ...\n");
	return 0;
}

static void __exit end_mod (void) /*Destructor*/
{
	printk (KERN_INFO "Module1 Ended ...\n");
}

module_init (init_mod);
module_exit (end_mod);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Uppsala University");
MODULE_DESCRIPTION ("Test Driver Module");
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>

/***********************PORT CREATION****************************/
#define OURMOUSE_BASE 0x300	//port address to receive mouse data

static struct miscdevice our_mouse = {
	OURMOUSE_MINOR, "ourmouse", &our_mouse_fops
};

__init ourmouse_init (void)
{
	// reserving port
	if (request_region (OURMOUSE_BASE, 3, "ourmouse") < 0) {
		printk(KERN_ERR "ourmouse: request_region failed.\n");
		return -ENODEV;
	}

	if (misc_register (&our_mouse) < 0) {
		printk (KERN_ERR "ourmouse: cannot register misc device.\n");
		release_region (OURMOUSE_BASE, 3);
		return -EBUSY;
	}
	return 0;
}

/***********************LOAD / UNLOAD****************************/
#ifdef MODULE
int init_module (void) // loading device driver
{
	if (ourmouse_init ()<0)
		return -ENODEV:
	return 0;
}

void cleanup_module (void) // unloading device driver
{
	misc_deregister (&our_mouse);
	free_region (OURMOUSE_BASE, 3);
}
#endif

/***********************FILE OPERATIONS****************************/
struct file_operations our_mouse_fops = {
	owner: THIS_MODULE,	/* Automatic usage management */
	read: read_mouse,	/* You can read a mouse */
	write: write_mouse,	/* This won’t do a lot */
	poll: poll_mouse,	/* Poll */
	open: open_mouse,	/* Called on open */
	release: close_mouse,	/* Called on close */
};

/***********************FIND EXISTENCE OF USERS****************************/
static int mouse_users = 0;	/* User count */
static int mouse_dx = 0;	/* Position changes */
static int mouse_dy = 0;	
static int mouse_event = 0;	/* Mouse has moved */

static int open_mouse (struct inode *inode, struct file *file)
{
	if(mouse_users++)
		return 0;

	// Users Queue
	if (request_irq (mouse_intr, OURMOUSE_IRQ, 0, "ourmouse", NULL))
	{
		mouse_users--;
		return -EBUSY;
	}

	mouse_dx = 0;
	mouse_dy = 0;
	mouse_event = 0;
	mouse_buttons = 0;
	return 0;
}

/***********************FREE USERS****************************/
static int close_mouse (struct inode *inode, struct file *file)
{
	if (--mouse_users)
		return 0;
	free_irq (OURMOUSE_IRQ, NULL);
	return 0;
}

/***********************WRITE INTO MOUSE****************************/
static ssize_t write_mouse (struct file *file, const char *buffer, size_t count, loff_t *ppos)
{
	return -EINVAL;
}

/***********************SPIN LOCK****************************/
static struct wait_queue *mouse_wait;
static spinlock_t mouse_lock = SPIN_LOCK_UNLOCKED;

static void ourmouse_interrupt (int irq, void *dev_id, struct pt_regs *regs)
{
	char delta_x;
	char delta_y;
	unsigned char new_buttons;

	delta_x = inb (OURMOUSE_BASE);
	delta_y = inb (OURMOUSE_BASE+1);
	new_buttons = inb (OURMOUSE_BASE + 2);

	// don't read when mouse is changing
	if (delta_x || delta_y || new_buttons != mouse_buttons)
	{
		/* Something happened */

		spin_lock (&mouse_lock);
		mouse_event = 1;
		mouse_dx += delta_x;
		mouse_dy += delta_y;
		mouse_buttons = new_buttons;
		spin_unlock (&mouse_lock);

		wake_up_interruptible (&mouse_wait);
	}
}

/***********************POLLING MOUSE EVENT/DATA****************************/
static unsigned int mouse_poll (struct file *file, poll_table *wait)
{
	poll_wait (file, &mouse_wait, wait);
	if (mouse_event)
		return POLLIN | POLLRDNORM;
	return 0;
}

/***********************VALIDATE DATA WHICH IS READ****************************/
static ssize_t mouse_read (struct file *file, char *buffer, size_t count, loff_t *pos)
{
	int dx, dy;
	unsigned char button;
	unsigned long flags;
	int n;

	if (count < 3)
		return -EINVAL;

	/* Wait for an event */
	while (!mouse_event)
	{
		if (file->f_flags & O_NDELAY)
			return -EAGAIN;
		interruptible_sleep_on (&mouse_wait);
		if (signal_pending (current))
			return -ERESTARTSYS;
	}

	/***********************DATA IN READ & PUT IN USERSPACE****************************/
	/* Grab the event */
	spinlock_irqsave (&mouse_lock, flags);

	dx = mouse_dx;
	dy = mouse_dy;
	button = mouse_buttons;

	if (dx <= -127)
		dx = -127;
	if (dx >= 127)
		dx = 127;
	if (dy <= -127)
		dy = -127;
	if (dy >= 127)
		dy = 127;

	mouse_dx -= dx;
	mouse_dy -= dy;

	if (mouse_dx == 0 && mouse_dy == 0)
		mouse_event = 0;
	spin_unlock_irqrestore (&mouse_lock, flags);

	/*
		data is sent to userspace
		1.	button pressed
		2.	dx
		3.	dy
	*/
	if (put_user (button | 0x80, buffer))
		return -EFAULT;
	if (put_user ((char)dx, buffer+1))
		return -EFAULT;
	if (put_user ((char)dy, buffer+2))
		return -EFAULT;
	
	for (n = 3; n < count; n++)
		if(put_user(0x00, buffer+n))
			return -EFAULT;

	return count;
}
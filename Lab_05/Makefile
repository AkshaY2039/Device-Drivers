# The kernel source is assumed to be installed at /usr/src/linux. If its at any other location on your system,
# specify the location in the KERNEL SOURCE variable in the makefile. The following Make File invokes the kernel's
# build system from the kernel source, and the kernel's make file will, in turn, invoke our Make File to build our
# first driver.

# Makefile : makefile of our first driver

# if KERNELRELEASE is defined , we ’ ve been invoked from the
# kernel build system and can use its language .
ifneq ($(KERNELRELEASE),)
	obj-m:=01_IOCTL_QUERY.o
# Otherwise we were called directly from the command line .
# Invoke the kernel build system .
else
	KERNEL_SOURCE:=/usr/src/linux-headers-$(shell uname -r)
	PWD:=$(shell pwd)
default :
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) modules
clean :
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=$(PWD) clean
endif
#	Linux Paths

##	Important Files Paths Explained
>	S.No. | Path | What is it for? | Detail
>	------|-----|-------------|------
>	1. | / | Root directory | root of the entire file system hierarchy
>	2. | /bin/ | Essential user command binaries | All the executable binary programs (file) required during booting, repairing, files required to run into single-user-mode, and other important, basic commands viz., cat, du, df, tar, rpm, wc, history, etc.
>	3. | /boot/ | Static Files of the Boot loader | Holds important files during boot-up process, including Linux Kernel.
>	4. | /cdrom/ | CD ROM | Mounts the CD Optical Disk
>	5. | /core | Core OS file (one file) | Image file of OS
>	6. | /dev/ | Device Files | Contains device files for all the hardware devices on the machine e.g., cdrom, cpu, etc
>	7. | /etc/ | Host-Specific Systen Configuration `required directories : opt, x11, sqml, xml` | Contains Application’s configuration files, startup, shutdown, start, stop script for every individual program
>	8. | /home/ | User Home Directories | Home directory of the users. Every time a new user is created, a directory in the name of user is created within home directory which contains other directories like Desktop, Downloads, Documents, etc
>	9. | /initrd.img | Initial RamDisk file | initrd (initial ramdisk) is a scheme for loading a temporary root file system into memory, which may be used as part of the Linux startup process
>	10. | /initrd.img.old | Initial RamDisk backup | backup of initial RamDisk file
>	11. | /lib/ | Essential Shared Libraries and Kernel Modules | The Lib directory contains kernel modules and shared library images required to boot the system and run commands in root file system.
>	12. | /lib64/ | Essential Shared Libraries and Kernel Modules for 64 bit arch | The Lib64 directory contains kernel modules and shared library images required to boot the 64 bit system and run commands in root file system.
>	13. | /lost+found/ | Broken and Lost files during unexpected shutdown | This Directory is installed during installation of Linux, useful for recovering files which may be broken due to unexpected shut-down.
>	14. | /media/ | Mount Point for Removable Media | Temporary mount directory is created for removable devices viz., media/cdrom
>	15. | /mnt/ | Mount Point for Temporarily Mounted File Systems | Temporary mount directory for mounting file system.
>	16. | /opt/ | Add-On Application Software Packages | Optional is abbreviated as opt. Contains third party application software. Viz., Java, etc.
>	17. | /proc/ | Virtual File System Documenting Kernel & Process Status as Text Files | A virtual and pseudo file-system which contains information about running process with a particular `Process-id` aka `pid`.
>	18. | /root/ | Home Directory for the Root User | This is the home directory of root user and should never be confused with `/`
>	19. | /run/ | runtime scratch directory | This directory is the only clean solution for early-runtime-dir problem.
>	20. | /sbin/ | System Binaries | Contains binary executable programs, required by System Administrator, for Maintenance. Viz., iptables, fdisk, ifconfig, swapon, reboot, etc.
>	21. | /srv/ | Data for Services and server provided by the system | Service is abbreviated as ‘srv‘. This directory contains server specific and service related files.
>	22. | /sys/ | System Files | Modern Linux distributions include a /sys directory as a virtual filesystem, which stores and allows modification of the devices connected to the system, whereas many traditional Unix-like operating systems use /sys as a symbolic link to the kernel source tree.
>	23. | /tmp/ | Temporary Files | System’s Temporary Directory, Accessible by users and root. Stores temporary files for user and system, till next boot.
>	24. | /usr/ | (Multi-) User Utilities and Applications `SECONDARY HIERARCHY (required directories : bin, include, lib, local, $bin, $make)` | Contains executable binaries, documentation, source code, libraries for second level program.
>	25. | /var/ | Variable Files `(contains files to which the system writes data during the course of its operation)` | Stands for variable. The contents of this file is expected to grow. This directory contains log, lock, spool, mail and temp files.
>	26. | /vmlinuz | Virtual Memory Linux | vmlinuz is the name of the Linux kernel executable. vmlinuz is a compressed Linux kernel, and it is capable of loading the operating system into memory so that the computer becomes usable and application programs can be run.
>	27. | /vmlinuz.old | Virtual Memory Linux Backup | backup of vmlinuz file
>	28. | /boot/vmlinuz | The Linux Kernel file | same as /vmlinuz in some operating systems
>	29. | /dev/hda | Device file for the first IDE HDD (Hard Disk Drive) | 
>	30. | /dev/hdc | Device file for the IDE Cdrom, commonly | 
>	31. | /dev/null | behaves as Void Device | A pseudo device, that don’t exist. Sometime garbage output is redirected to /dev/null, so that it gets lost, forever
>	32. | /etc/bashrc | Contains system defaults and aliases used by bash shell | 
>	33. | /etc/crontab | A shell script to run specified commands on a predefined time Interval |
>	34. | /etc/exports | Information of the file system available on network | 
>	35. | /etc/fstab | Information of Disk Drive and their mount point | 
>	36. | /etc/group | Information of Security Group | 
>	37. | /etc/grub.conf | grub bootloader configuration file | 
>	38. | /etc/init.d | Service startup Script | 
>	39. | /etc/lilo.conf | lilo bootloader configuration file | 
>	40. | /etc/hosts | Information of Ip addresses and corresponding host names | 
>	41. | /etc/hosts.allow | List of hosts allowed to access services on the local machine | 
>	42. | /etc/host.deny | List of hosts denied to access services on the local machine | 
>	43. | /etc/inittab | INIT process and their interaction at various run level | 
>	44. | /etc/issue | Allows to edit the pre-login message | 
>	45. | /etc/modules.conf | Configuration files for system modules | 
>	46. | /etc/motd | motd stands for Message Of The Day, The Message users gets upon login | 
>	47. | /etc/mtab | Currently mounted blocks information | 
>	48. | /etc/passwd | Contains password of system users in a shadow file, a security implementation | 
>	49. | /etc/printcap | Printer Information | 
>	50. | /etc/profile | Bash shell defaults | 
>	51. | /etc/profile.d | Application script, executed after login | 
>	52. | /etc/rc.d | Information about run level specific script | 
>	53. | /etc/rc.d/init.d | Run Level Initialisation Script | 
>	54. | /etc/resolv.conf | Domain Name Servers (DNS) being used by System | 
>	55. | /etc/securetty | Terminal List, where root login is possible | 
>	56. | /etc/skel | Script that populates new user home directory | 
>	57. | /etc/termcap | An ASCII file that defines the behaviour of Terminal, console and printers | 
>	58. | /etc/X11 | Configuration files of X-window System | 
>	59. | /usr/bin | Normal user executable commands | 
>	60. | /usr/bin/X11 | Binaries of X windows System | 
>	61. | /usr/include | Contains include files used by ‘c‘ program | 
>	62. | /usr/share | Shared directories of man files, info files, etc | 
>	63. | /usr/lib | Library files which are required during program compilation | 
>	64. | /usr/sbin | Commands for Super User, for System Administration | 
>	65. | /proc/cpuinfo | CPU Information | 
>	66. | /proc/filesystems | File-system Information being used currently | 
>	67. | /proc/interrupts | Information about the current interrupts being utilised currently | 
>	68. | /proc/ioports | Contains all the Input/Output addresses used by devices on the server | 
>	69. | /proc/meminfo | Memory Usages Information | 
>	70. | /proc/modules | Currently using kernel module | 
>	71. | /proc/mount | Mounted File-system Information | 
>	72. | /proc/stat | Detailed Statistics of the current System | 
>	73. | /proc/swaps | Swap File Information | 
>	74. | /version | Linux Version Information | 
>	75. | /var/log/lastlog | log of last boot process | 
>	76. | /var/log/messages | log of messages produced by syslog daemon at boot | 
>	77. | /var/log/wtmp | list login time and duration of each user on the system currently | 

###	Reference
1.	[Linux Directory Structure and Important Files Paths Explained](https://www.tecmint.com/linux-directory-structure-and-important-files-paths-explained/)
2.	[The Linux Information Project](http://www.linfo.org/index.html)
3.	[Linux Filesystem Hierarchy](http://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/)
4.	[Linux initial RAM disk (initrd) overview](https://www.ibm.com/developerworks/library/l-initrd/index.html)
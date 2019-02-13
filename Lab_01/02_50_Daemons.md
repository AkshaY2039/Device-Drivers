#	Linux Daemons

##	Daemons in Linux
>	S.No. | Daemon Name | Detail
>	------|-----|------
>	1 | systemd | `systemd` is a system and service manager for Linux operating systems. When run as first process on boot (as PID 1), it acts as init system that brings up and maintains userspace services
>	2 | kthreadd | `kthreadd` is the kernel thread daemon.  All kthreads are forked off this thread
>	3 | rcu_sched | RCU stands for `Read-copy update`. The rcu_sched is specifically used for synchronization to allows reads to occur concurrently with any updates. The RCU supports concurrency between a single updater and multiple readers
>	4 | kauditd | `kauditd` kernel process, which is a part of the Linux kernel responsible for the kernel audit events (and communicates with the auditd process). The special brackets surrounding it are telling you that this is not a regular (userland) process (launched through a command), but a kernel process (started/managed by the Linux kernel itself)
>	5 | khungtaskd | `Khungtaskd` is special kernel thread which gets scheduled every 120 seconds and check status of all process.
>	6 | ksmd | `KSM` is a memory-saving de-duplication feature, enabled by CONFIG_KSM=y, added to the Linux kernel in 2.6.32. The `KSM daemon` ksmd periodically scans those areas of user memory which have been registered with it, looking for pages of identical content which can be replaced by a single write-protected page (which is automatically copied if a process later wants to update its content).
>	7 | khugepaged | It is to support large pagesize memory architecture. In Linux, memory is managed in blocks known as "pages" - whic is the basic unit of virtual memory.. If some task quits and more hugepages become available (either immediately in the buddy or through the VM), guest physical memory backed by regular pages should be relocated on hugepages automatically (with khugepaged)
>	8 | kintegrityd | its a workqueue (kernel thread + queue for bottom half processing) responsible for creating a payload for block devices integrity mean when you write data and want to be sure it will not change by mistake (hardware fail, bug, …) you write also some extra data (payload) to check its integrity, this is done in parallel using this thread
>	9 | kblockd | the kblockd kernel threads are responsible for performing low-level disk operations
>	10 | md | The md driver provides virtual devices that are created from one or more independent underlying devices.
>	11 | watchdogd | 
>	12 | kthrotld | 
>	13 | lvmetad | 
>	14 | systemd-udevd | 
>	15 | thermald | 
>	16 | avahi-daemon | 
>	17 | acpid | 
>	18 | rsyslogd | 
>	19 | systemd-logind | 
>	20 | cupsd | 
>	21 | accounts-daemon | 
>	22 | dbus-daemon | 
>	23 | avahi-daemon | 
>	24 | cups-browsed | 
>	25 | polkitd | 
>	26 | colord | 
>	27 | mysqld | 
>	28 | teamviewerd | 
>	29 | upowerd | 
>	30 | systemd | 
>	31 | gnome-keyring-d | 
>	32 | dbus-daemon | 
>	33 | csd-clipboard | 
>	34 | csd-keyboard | 
>	35 | csd-background | 
>	36 | csd-sound | 
>	37 | syndaemon | 
>	38 | gvfsd | 
>	39 | dbus-daemon | 
>	40 | rtkit-daemon | 
>	41 | udisksd | 
>	42 | goa-daemon | 
>	43 | obexd | 
>	44 | gvfsd-dnssd | 
>	45 | Microsoft.VSCod | 
>	46 |  | 
>	47 |  | 
>	48 |  | 
>	49 |  | 
>	50 |  | 

###	Reference
1.	Commands to find out about Daemons
	*	ps -e | grep -e d$ -e daemon
	*	service --status-all | grep "+"
	*	systemctl list-units
2.	[systemd.index — List all manpages from the systemd project](https://www.freedesktop.org/software/systemd/man/index.html)
3.	[what is the [kthreadd] process?](http://www.linuxvox.com/post/what-is-the-kthreadd-process/)
4.	[Kernel Feature's Documentation](https://www.kernel.org/doc/Documentation/)
5.	
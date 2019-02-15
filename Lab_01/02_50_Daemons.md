#	Linux Daemons

##	Daemons in Linux
>	S.No. | Daemon Name | Detail
>	------|-----|------
>	1 | systemd | `systemd` is a system and service manager for Linux operating systems. When run as first process on boot (as PID 1), it acts as init system that brings up and maintains userspace services
>	2 | kthreadd | `kthreadd` is the kernel thread daemon.  All kthreads are forked off this thread
>	3 | rcu_sched | RCU stands for `Read-copy update`. The rcu_sched is specifically used for synchronization to allows reads to occur concurrently with any updates. The RCU supports concurrency between a single updater and multiple readers
>	4 | kauditd | `kauditd` kernel process, which is a part of the Linux kernel responsible for the kernel audit events (and communicates with the auditd process). The special brackets surrounding it are telling you that this is not a regular (userland) process (launched through a command), but a kernel process (started/managed by the Linux kernel itself)
>	5 | khungtaskd | `Khungtaskd` is special kernel thread which gets scheduled every 120 seconds and check status of all process
>	6 | ksmd | `KSM` is a memory-saving de-duplication feature, enabled by CONFIG_KSM=y, added to the Linux kernel in 2.6.32. The `KSM daemon` ksmd periodically scans those areas of user memory which have been registered with it, looking for pages of identical content which can be replaced by a single write-protected page (which is automatically copied if a process later wants to update its content)
>	7 | khugepaged | It is to support large pagesize memory architecture. In Linux, memory is managed in blocks known as "pages" - whic is the basic unit of virtual memory.. If some task quits and more hugepages become available (either immediately in the buddy or through the VM), guest physical memory backed by regular pages should be relocated on hugepages automatically (with khugepaged)
>	8 | kintegrityd | its a workqueue (kernel thread + queue for bottom half processing) responsible for creating a payload for block devices integrity mean when you write data and want to be sure it will not change by mistake (hardware fail, bug, …) you write also some extra data (payload) to check its integrity, this is done in parallel using this thread
>	9 | kblockd | the kblockd kernel threads are responsible for performing low-level disk operations
>	10 | md | `Multiple Device` driver aka Linux Software RAID. The md driver provides virtual devices that are created from one or more independent underlying devices
>	11 | watchdogd | `watchdogd` is a software watchdog daemon. It opens /dev/watchdog, and keeps writing to it often enough to keep the kernel from resetting, at least once per minute
>	12 | kthrotld | `kthrotld` controlls IO bandwidth on a request queue, by throttling requests
>	13 | lvmetad | LVM metadata cache daemon. The `lvmetad` daemon caches LVM metadata so that LVM commands can read metadata from the cache rather than scanning disks.  This can be an advantage because scanning disks is time consuming and may interfere with the normal work of the system.  lvmetad can be a disadvantage when disk event notifications from the system are unreliable
>	14 | systemd-udevd | systemd-udevd listens to kernel uevents. For every event, systemd-udevd executes matching instructions specified in udev rules
>	15 | thermald | Linux thermal daemon (`thermald`) monitors and controls temperature in laptops, tablets PC with the latest Intel sandy bridge and latest Intel CPU releases. Once the system temperature reaches a certain threshold, the Linux daemon activates various cooling methods to try to cool the system
>	16 | avahi-daemon | The `Avahi mDNS/DNS-SD daemon` implements Apple's Zeroconf architecture (also known as "Rendezvous" or "Bonjour"). The daemon registers local IP addresses and static services using mDNS/DNS-SD and provides two IPC APIs for local programs to make use of the mDNS record cache the avahi-daemon maintains
>	17 | acpid | Advanced Configuration and Power Interface event daemon. `acpid` is designed to notify user-space programs of ACPI events
>	18 | rsyslogd | System Logging Daemon
>	19 | systemd-logind | Login Daemon
>	20 | cupsd | CUPS Scheduler Daemon
>	21 | accounts-daemon | Accounts Daemon
>	22 | dbus-daemon | D-Bus System Message Bus Daemon
>	23 | gvfsd | `gnome Virtual File System` master daemon that handles coordinating mounts, and then each mount is (typically) in its own daemon process (although mounts can share daemon process)
>	24 | gvfsd-dnssd | browses DNS-SD for as a mount Backend for GVFS
>	25 | cups-browsed | Make remote CUPS printers available locally
>	26 | polkitd | Authenticate and Authorize Users to Run Privileged Tasks
>	27 | colord | Manage, Install and Generate Color Profiles
>	28 | mysqld | MySQL Community Server Daemon
>	29 | teamviewerd | TeamViewer remote control daemon
>	30 | upowerd | Daemon for power management
>	31 | obexd | `OBject EXchange` is communication protocol to facilitate the exchange of the binary objects between the devices. `obexd` handles the object exchange requests. OBEX has now been integrated into BlueZ (official Linux Bluetooth protocol stack)
>	32 | gnome-keyring-d | `Gnome Keyring Daemon` is a service that stores your passwords, keys and username together with a small amount of relevant metadata
>	33 | Microsoft.VSCod | MS Visual Studio Code Daemon
>	34 | csd-clipboard | `Cinnamon Settings Daemon - Clipboard` for cinnamon desktop manager
>	35 | csd-keyboard | `Cinnamon Settings Daemon - Keyboard` for cinnamon desktop manager
>	36 | csd-background | `Cinnamon Settings Daemon - Background` for cinnamon desktop manager
>	37 | csd-sound | `Cinnamon Settings Daemon - Sound` for cinnamon desktop manager
>	38 | syndaemon | `syndaemon` monitors keyboard activity and disables the touchpad when the keyboard is being used
>	39 | syslogd | `syslogd` is the most common logger for Linux and Unix. The syslogd daemon handles messages from servers and programs
>	40 | rtkit-daemon | RealtimeKit Scheduling Policy Daemon
>	41 | udisksd | Disk Manager daemon
>	42 | goa-daemon | The `goa-daemon` provides the org.gnome.OnlineAccounts name on the session message bus. Its automatically started by dbus-daemon
>	43 | inetd | Listens for network connection requests. If a request is accepted, it can launch a background daemon to handle the request, was known as the super server for this reason. Some systems use the replacement command xinetd
>	44 | httpd | HTTP Web Server Daemon
>	45 | nfsd | Processes NFS operation requests from client systems. Historically each nfsd daemon handled one request at a time, so it was normal to start multiple copies
>	46 | sshd | Listen for secure shell requests from clients
>	47 | syncd | Periodically keeps the file systems synchronized with system memory
>	48 | lpd | The line printer daemon that manages prinder spooling
>	49 | biod | Works in cooperation with the remote nfsd to handle client NFS requests
>	50 | crond | Time-based job scheduler, runs jobs in the background

###	Reference
1.	Commands to find out about Daemons
	*	ps -e | grep -e d$ -e daemon
	*	service --status-all | grep "+"
	*	systemctl list-units
2.	[systemd.index — List all manpages from the systemd project](https://www.freedesktop.org/software/systemd/man/index.html)
3.	[what is the [kthreadd] process?](http://www.linuxvox.com/post/what-is-the-kthreadd-process/)
4.	[Kernel Feature's Documentation](https://www.kernel.org/doc/Documentation/)
5.	[man7.org](http://man7.org/index.html)
6.	[List of UNIX Daemons](https://www.wikipedia.org/en/wiki/List_of_Unix_daemons)
7.	[Gnome Virtual File System](https://www.wikipedia.org/en/wiki/GVfs)
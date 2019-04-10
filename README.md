#	Device-Drivers
Device Drivers Lab Work
-	Course Code : COM405P
-	Course Faculty : Dr. Shankaran Vaidyanathan

Machine Description : 
-	[lscpu](./Lab_00/lscpu.txt)
-	[lshw](./Lab_00/lshw.txt)
-	[screenfetch](./Lab_00/screenfetch.txt)
-	[running daemons](./Lab_00/running_daemons.txt)
-	[drivers](./Lab_00/drivers.txt)
 -- --

##	Lab 00 : Basics of Linux, UNIX and Shell Scripting - 20190101
1.	Linux Commands
2.	Linux vs UNIX (Differences)
3.	Shell scripting

##	Lab 01 : More towards Device Drivers and Shell Script - 20190108
1.	List atleast 50 paths with files & explain what it does.
2.	List atleast 50 daemons (E.g. syslogd).
3.	List all Device Drivers from your OS.
4.	Write a shell script with atleast 100 lines.
	*	Reference: [Alexander Epstein - Bash Snippets](https://github.com/alexanderepstein/Bash-Snippets/blob/master/currency/currency)
5.	Write a C program & attach it with Kernel. `(Done in Lab 02)`
6.	Download source code of a command not available in your OS & add it to your Kernel.

##	Lab 02 : Some Hands On with Device Drivers - 20190122
0.	Example
	*	Making a Device Driver Module and Attach with Kernel [Tutorial on Linux Device Driver](http://www.it.uu.se/edu/course/homepage/pins/vt15/labs/tutorial-DD.pdf)
	*	Types of Device Drivers
	*	File Systems and How Hard disk is divided?
	*	BOOT FILE
1.	Write a Kernel Module and attach to Kernel.

##	Lab 03 :  - 20190129
0.	Example
	*	[arunpn123/keylogger](https://github.com/arunpn123/keylogger/blob/master/keylogger.c)
1.	Write a keyboard sniffer / keylogger kernel module.

##	Lab 04 :  - 20190205

##	Lab 05 :  - 20190213
0.	[IOCTL](https://github.com/DukeOwlington/ioctl_lkm)
1.	Write IOCTL module.

##	Lab 06 :  - 20190219
0.	Mouse Drivers Example
	*	[Mouse Drivers - Alan Cox](./Lab_06/Mouse_Drivers__Alan_Cox.pdf)
	*	[Linux Device driver module that changes brightness of the screen on click.](https://github.com/kajalv/mouse-driver/blob/master/dev_driver.c)
1.	Write a mouse driver module to track pointer position.

##	Lab 07 :  - 20190305

##	Lab 08 :  - 20190312
0.	Network Device Drivers
1.	Try changing the IP of your 

##	End Sem Lab Exam : 20190409
1.	Write a shell program which takes input as a character and prints output as its ASCII value.
2.	Write a keyboard logger device driver which prints or logs keys in REVERSE order. Example - if keys pressed are "BAMOZ" then the output is "ZOMAB"

##	Assignments
1.	Write an application in C to capture all network packets & display any password if it is found in HTTP packets.
	-	[01_HTTP_PW_Capture.c](./Assignments/01_HTTP_PW_Capture.c)
2.	20 interesting points about Network Device Drivers
	-	[02_Network_Device_Drivers.md](./Assignments/02_Network_Device_Drivers.md)
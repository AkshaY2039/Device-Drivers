#	BOOT FILE - FAT 24

##	BOOT FILE
OFFSET | #Bytes | Description
-------|--------|------------
0x00 | 3 | Instruction(s) to jump to the bootstrap code
0x03 | 8 | Name of the formatting OS
0x0B | 2 | Bytes per Sector
0x0D | 1 | Sectors per Cluster
0x0E | 2 | Reserved sectors from the start of the volume
0x10 | 1 | Number of FAT copies
0x11 | 2 | Number of possible root entries
0x13 | 2 | Small number of sectors
0x15 | 1 | Media Descriptor
0x16 | 2 | Sectors per FAT
0x18 | 2 | Sectors per track
0x1A | 2 | Number of Heads
0x1C | 4 | Hidden sectors
0x20 | 4 | Large number of sectors (used when volume size exceeds 32MB)
0x24 | 1 | Drive number
0x25 | 1 | Reserved
0x26 | 1 | Extended boot signature (indicates that the next three fields are available)
0x27 | 4 | Volume serial number
0x2B | 11 | Volume Label (should be same as in the root directory)
0x36 | 8 | File System type (should be FAT12)
0x3E | 448 | Bootstrap Code
0x1FE | 2 | Boot sector signature (should be 0xAA55)
-- --

##	ROOT - DIRECTORY
OFFSET | #Bytes | Description
-------|--------|------------
0x00 | 8 | The filename
0x08 | 3 | The file extension
0x0B | 1 | File attributes
0x0C | 1 | Reserved for Windows NT
0x0D | 1 | Creation - Millisecond stamp (actual 100th of a second)
0x0E | 2 | Creation time
0x10 | 2 | Creation date
0x12 | 2 | Last access date
0x14 | 2 | Reserved for FAT32
0x16 | 2 | Last write time
0x18 | 2 | Last write date
0x1A | 2 | First logical cluster of the file
0x1C | 4 | File size in bytes
-- --
# DISKO 2

## Description

Can you find the flag in this disk image? The right one is Linux! One wrong step and its all gone!
Download the disk image [here](https://artifacts.picoctf.net/c/539/disko-2.dd.gz).

### Solution

![alt text](image.png)

```sh
# pre-req -- why/////// ----- we are on macos
brew install macfuse
brew install mtools
brew install e2fsprogs e2tools
# ---

curl https://artifacts.picoctf.net/c/539/disko-2.dd.gz -O
gunzip disko-2.dd.gz
strings disko-2.dd | grep "pico"
fdisk -d disko-2.dd 
# > 2048,51200,0x83,-,0,32,33,3,80,13
# > 53248,65536,0x0B,-,3,80,14,7,100,29
# > 0,0,0x00,-,0,0,0,0,0,0
# > 0,0,0x00,-,0,0,0,0,0,0

# Partition 1 (Linux ext4)
dd if=disko-2.dd of=part1.dd bs=512 skip=2048 count=51200
# > 51200+0 records in
# > 51200+0 records out
# > 26214400 bytes transferred in 0.106203 secs (246832952 bytes/sec)

# Partition 2 (FAT32)
dd if=disko-2.dd of=part2.dd bs=512 skip=53248 count=65536
# > 65536+0 records in
# > 65536+0 records out
# > 33554432 bytes transferred in 0.135409 secs (247800604 bytes/sec)
# Attach partition 1 (ext4 — needs ext4fuse for macOS)
hdiutil attach -imagekey diskimage-class=CRawDiskImage -nomount part1.dd
# > /dev/disk6
# Attach partition 2 (FAT32 — macOS can mount natively)
hdiutil attach -imagekey diskimage-class=CRawDiskImage -nomount part2.dd
# > /dev/disk7
diskutil list /dev/disk6
# > /dev/disk6 (disk image):
# >     #:                       TYPE NAME                    SIZE       IDENTIFIER
# >     0:                                                   +26.2 MB    disk6
diskutil list /dev/disk7                   
# > /dev/disk7 (disk image):
# >    #:                       TYPE NAME                    SIZE       IDENTIFIER
# >    0:                            NO NAME                +33.6 MB    disk7
mcopy -i part2.dd ::/LOG ./LOG . 
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
# > Attempt to copy file on itself
mcopy -i part2.dd -s "::LOG" .
strings part2.dd | grep pico | grep -v "picoCTF{4_P4Rt_1t_i5_903a13fd}" | grep -v "picoCTF{4_P4Rt_1t_i5_0d93a13f}" | grep -v "picoCTF{4_P4Rt_1t_i5_931afd03}" | grep -v "picoCTF{4_P4Rt_1t_i5_1daf9033" | grep -v "picoCTF{4_P4Rt_1t_i5_a1df3903}" | grep -v "picoCTF{4_P4Rt_1t_i5_39fa01d3}" | grep -v "picoCTF{4_P4Rt_1t_i5_f9331ad0}" | grep -v "picoCTF{4_P4Rt_1t_i5_af9d0133}" | grep -v "picoCTF{4_P4Rt_1t_i5_af91303d}" | grep -v "picoCTF{4_P4Rt_1t_i5_91fda330}" | grep -v "picoCTF{4_P4Rt_1t_i5_339d0fa1}" | grep -v "picoCTF{4_P4Rt_1t_i5_09a331df}" | grep -v "picoCTF{4_P4Rt_1t_i5_09a331df}" | grep -v "picoCTF{4_P4Rt_1t_i5_039fda13}" | grep -v "picoCTF{4_P4Rt_1t_i5_331d0f9a}" | grep -v "picoCTF{4_P4Rt_1t_i5_903d13af}" | grep -v "picoCTF{4_P4Rt_1t_i5_913a30df}" | grep pico
```

![log_dir](image-1.png)

![invalid flag](image-2.png)

![no flag](image-3.png)

```sh

```

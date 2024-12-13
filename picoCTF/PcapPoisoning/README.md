# PcapPoisoning

## Description

How about some hide and seek heh? Download this [file](https://artifacts.picoctf.net/c/375/trace.pcap) and find the flag.

## Solution

An easy flag. We can use the `tcpdump` command to output contents of the `pcap` file and `grep` for the `flag`,

```sh
➜  PcapPoisoning git:(main) ✗ tcpdump -r trace.pcap | grep pico
reading from file trace.pcap, link-type IPV4 (Raw IPv4)
07:26:08.123304 IP 172.16.0.2.ftp-data > 10.253.0.6.ftp: Flags [S], seq 0:42, win 8192, length 42: FTP: picoCTF{P64P_4N4L7S1S_SU55355FUL_5b6a6061} [|ftp]
```

The flag is `picoCTF{P64P_4N4L7S1S_SU55355FUL_5b6a6061}`.

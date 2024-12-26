# Packets Primer

## Description

Download the packet capture file and use packet analysis software to find the flag.

- [Download packet capture](https://artifacts.picoctf.net/c/196/network-dump.flag.pcap)

## Solution

Download the file to this directory using the below command,

```sh
curl -O https://artifacts.picoctf.net/c/196/network-dump.flag.pcap
```

The flag is not in the file per se, it is part of the inner binary. You can use `strings -10 network-dump.flag.pcap` to get the flag, which is the following,

```text
picoCTF{p4ck37_5h4rk_01b0a0d6}
```

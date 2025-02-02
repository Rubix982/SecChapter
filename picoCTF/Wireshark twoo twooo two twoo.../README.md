# Wireshark twoo twooo two twoo...

## Category

Forensics.

## Description

Can you find the flag? [shark2.pcapng](https://mercury.picoctf.net/static/23653a37cdf4727dfbf0493d80143b3f/shark2.pcapng).

## Solution

Download the PCAP,

```sh
curl -O https://mercury.picoctf.net/static/23653a37cdf4727dfbf0493d80143b3f/shark2.pcapng
```

If you use `tcpdump`, you will find many `picoCTF`, but none matching.

Was unable to find something for for time. Found a solution by `Dvd848` -> https://github.com/Dvd848.

You can run the below query with `tshark`,

```sh
tshark -nr shark2.pcapng -Y 'dns && ip.src == 192.168.38.104 && frame contains "local" && ip.dst==18.217.1.57' | awk '{ print $12}' | awk -F. '{ print $1 }' | tr -d "\n"
```

It will produce a base64 type string,

```plaintext
cGljb0NURntkbnNfM3hmMWxfZnR3X2RlYWRiZWVmfQ==fQ==%
```

Pass to `base64`,

```sh
echo "cGljb0NURntkbnNfM3hmMWxfZnR3X2RlYWRiZWVmfQ==" | base64 -d
```

Flag -> `picoCTF{dns_3xf1l_ftw_deadbeef}`.

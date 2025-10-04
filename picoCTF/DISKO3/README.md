# DISKO 3

Can you find the flag in this disk image? This time, its not as plain as you think it is!
Download the disk image [here](https://artifacts.picoctf.net/c/544/disko-3.dd.gz).

## Solution

```sh
curl https://artifacts.picoctf.net/c/544/disko-3.dd.gz -O
gunzip disko-3.dd.gz
mkdir mnt
hdiutil attach -imagekey diskimage-class=CRawDiskImage -mountpoint mnt disko-3.dd # macos cmd
ls mnt
hdiutil detach mnt
```

![flag file](image.png)

Flag: `picoCTF{n3v3r_z1p_2_h1d3_26d4f233}`

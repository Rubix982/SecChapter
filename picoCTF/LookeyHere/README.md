# Lookey Here

## Description

Attackers have hidden information in a very large mass of data in the past, maybe they are still doing it. Download the data [here](https://artifacts.picoctf.net/c/126/anthem.flag.txt).

## Solution

Download the file with the command,

```sh
curl -O https://artifacts.picoctf.net/c/126/anthem.flag.txt
```

Simply `grep` and get the flag in the file,

![grep-anthem-flag](image.png)

Thus, the flag is `picoCTF{gr3p_15_@w3s0m3_2116b979}`.

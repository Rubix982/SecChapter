# extension

## Description

This is a really weird text file [TXT](https://jupiter.challenges.picoctf.org/static/e7e5d188621ee705ceeb0452525412ef/flag.txt)? Can you find the flag?

## Solution

```sh
curl -LO https://jupiter.challenges.picoctf.org/static/e7e5d188621ee705ceeb0452525412ef/flag.txt
file flag.txt flag.png
open flag.png
```

![flag](image.png)

Flag text -> `picoCTF{now_you_know_about_extensions}`.

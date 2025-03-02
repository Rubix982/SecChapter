# repetitions

## Description

Can you make sense of this file?
Download the file [here](https://artifacts.picoctf.net/c/477/enc_flag).

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c/477/enc_flag
cat enc_flag | tr -d '\n' | base64 -d | base64 -d | base64 -d | base64 -d | base64 -d | base64 -d
```

Flag -> `picoCTF{base64_n3st3d_dic0d!n8_d0wnl04d3d_de523f49}`.

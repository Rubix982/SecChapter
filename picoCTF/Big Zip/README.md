# Big Zip

## Description

Unzip this archive and find the flag. [Download zip file](https://artifacts.picoctf.net/c/503/big-zip-files.zip).

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c/503/big-zip-files.zip
unzip big-zip-files.zip && cd big-zip-files
grep -rn "pico" # picoCTF{gr3p_15_m4g1c_ef8790dc}
```

Flag -> `picoCTF{gr3p_15_m4g1c_ef8790dc}`.

# Commitment Issues

## Description

I accidentally wrote the flag down. Good thing I deleted it!
You download the challenge files here - [challenge.zip](https://artifacts.picoctf.net/c_titan/137/challenge.zip).

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c_titan/137/challenge.zip
unzip challenge.zip
cd drop-in
git checkout ea859bf3b5d94ee74ce5ee1afa3edd7d4d6b35f0
cat message.txt
```

Flag -> `picoCTF{s@n1t1z3_cf09a485}`.

## Writeup

Once you commit credentials, you have sinned greatly.

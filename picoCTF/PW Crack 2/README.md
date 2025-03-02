# PW Crack 2

## Description

Can you crack the password to get the flag?
Download the password checker [here](https://artifacts.picoctf.net/c/15/level2.py) and you'll need the encrypted [flag](https://artifacts.picoctf.net/c/15/level2.flag.txt.enc) in the same directory too.

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c/15/level2.py
curl -LO https://artifacts.picoctf.net/c/15/level2.flag.txt.enc
```

Just print password,

```python
print(chr(0x33) + chr(0x39) + chr(0x63) + chr(0x65)) # 39ce
```

Run the script. Provide the password. The flag is `picoCTF{tr45h_51ng1ng_502ec42e}`.

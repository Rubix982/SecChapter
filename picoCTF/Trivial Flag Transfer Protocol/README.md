# Trivial Flag Transfer Protocol

## Description

Figure out how they moved the [flag](https://mercury.picoctf.net/static/e4836d9bcc740d457f4331d68129a0bc/tftp.pcapng).

## Solution

```sh
curl -LO https://mercury.picoctf.net/static/e4836d9bcc740d457f4331d68129a0bc/tftp.pcapng
```

Setting up `steghide` on MacOS is a no-no. :(

After many hours of scripting, here is the solution -> https://medium.com/@quackquackquack/picoctf-trivial-flag-transfer-protocol-writeup-20c5d2d0dfdf.

Flag -> `picoCTF{h1dd3n_1n_pLa1n_51GHT_18375919}`.

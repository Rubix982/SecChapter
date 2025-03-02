# format string 0

## Description

Can you use your knowledge of format strings to make the customers happy?
Download the binary [here](https://artifacts.picoctf.net/c_mimas/68/format-string-0).
Download the source [here](https://artifacts.picoctf.net/c_mimas/68/format-string-0.c).

> Connect with the challenge instance here:
> nc mimas.picoctf.net 59626

## Solution

```sh
curl -LO https://artifacts.picoctf.net/c_mimas/68/format-string-0
curl -LO https://artifacts.picoctf.net/c_mimas/68/format-string-0.c
nc mimas.picoctf.net 59626
# Provide Breakf@st_BurgerBreakf@st_BurgerBreakf@st_Burger
```

Flag -> `picoCTF{7h3_cu570m3r_15_n3v3r_SEGFAULT_c8362f05}`.

## Writeup

Providing more characters than the limit allows causes an overflow. It's that simple. Writers should have used a limit specifier with `scanf`, and `puts` instead of `scanf`.

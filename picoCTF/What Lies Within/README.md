# What Lies Within

## Description

There's something in the [building](https://jupiter.challenges.picoctf.org/static/011955b303f293d60c8116e6a4c5c84f/buildings.png). Can you retrieve the flag?

## Solution

```sh
curl -LO https://jupiter.challenges.picoctf.org/static/011955b303f293d60c8116e6a4c5c84f/buildings.png
zsteg -a buildings.png
➜  What Lies Within git:(main) ✗ zsteg -a buildings.png 
b1,r,lsb,xy         .. text: "^5>R5YZrG"
b1,rgb,lsb,xy       .. text: "picoCTF{h1d1ng_1n_th3_b1t5}"
b1,abgr,msb,xy      .. file: PGP Secret Sub-key -
b2,b,lsb,xy         .. text: "XuH}p#8Iy="
b3,abgr,msb,xy      .. text: "t@Wp-_tH_v\r"
b3p,r,msb,xy        .. text: "R\t\t\t\t\t\tII\t[[[["
b3p,g,lsb,xy        .. text: "\n\nJJJJ\nJP"
b3p,g,msb,xy        .. text: "RRRR\t\t\tY["
b3p,b,msb,xy        .. text: "[KRR[R\nY"
b3p,rgb,msb,xy      .. text: "AAARRQIK[HJJYZ"
b3p,bgr,lsb,xy      .. text: "XZ@XX@@X"
b4,r,lsb,xy         .. text: "fdD\"\"\"\" "
b4,r,msb,xy         .. text: "%Q#gpSv0c05"
b4,g,lsb,xy         .. text: "fDfffDD\"\""
...
```

Flag -> `picoCTF{h1d1ng_1n_th3_b1t5}`.

# where are the robots

## Description

Can you find the robots?

1. [Link 1](https://jupiter.challenges.picoctf.org/problem/36474/)
2. [Link 2](http://jupiter.challenges.picoctf.org:36474)

## Solution

Append "robots.txt" at the end of the URL for "Link 1", like [this](https://jupiter.challenges.picoctf.org/problem/36474/robots.txt). We get an output,

```text
User-agent: *
Disallow: /477ce.html
```

Now visit [this route](https://jupiter.challenges.picoctf.org/problem/36474/477ce.html).

Flag -> `picoCTF{ca1cu1at1ng_Mach1n3s_477ce}`.

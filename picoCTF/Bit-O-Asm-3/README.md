# Bit-O-Asm-3

We are given the below file contents,

```asm
<+0>:     endbr64 
<+4>:     push   rbp
<+5>:     mov    rbp,rsp
<+8>:     mov    DWORD PTR [rbp-0x14],edi
<+11>:    mov    QWORD PTR [rbp-0x20],rsi
<+15>:    mov    DWORD PTR [rbp-0xc],0x9fe1a
<+22>:    mov    DWORD PTR [rbp-0x8],0x4
<+29>:    mov    eax,DWORD PTR [rbp-0xc]
<+32>:    imul   eax,DWORD PTR [rbp-0x8]
<+36>:    add    eax,0x1f5
<+41>:    mov    DWORD PTR [rbp-0x4],eax
<+44>:    mov    eax,DWORD PTR [rbp-0x4]
<+47>:    pop    rbp
<+48>:    ret
```

We have to find out the value of `eax` by the end of the execution.

`eax` is first mentioned here,

```asm
<+29>:    mov    eax,DWORD PTR [rbp-0xc]
```

In the above, we are moving `rbp-0xc` into `eax`, and we previously moved `0x9fe1a` into `rbp-0xc`,

```asm
<+15>:    mov    DWORD PTR [rbp-0xc],0x9fe1a
```

`0x9fe1a` is `654874` in decimal, so `eax` is `654874` currently.

In the next line, we get an `imul` operation for `integer mulitplication`,

```asm
<+32>:    imul   eax,DWORD PTR [rbp-0x8]
```

Previously `0x4` was moved into `rbp-0x8`, with the below line,

```asm
<+22>:    mov    DWORD PTR [rbp-0x8],0x4
```

`0x4` is simply `4` in decimal.

So `eax` is now,

```
eax := eax * 4
eax = 654874 * 4
eax = 2619496
```

Next, we add `0x1f5` to `eax` with the below line,

```asm
<+36>:    add    eax,0x1f5
```

`0x1f5` is `501` in decimal.

So `eax` is now,

```
eax := eax + 501
eax = 2619496 + 501
eax = 2619997
```

We then have the two lines,

```
<+41>:    mov    DWORD PTR [rbp-0x4],eax
<+44>:    mov    eax,DWORD PTR [rbp-0x4]
```

This does nothing. It moves the value of `eax` back into itself.

So our final answer is `picoCTF{2619997}`.

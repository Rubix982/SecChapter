# Redaction Gone Wrong

## Description

Now you DON’T see me.
This [report](https://artifacts.picoctf.net/c/84/Financial_Report_for_ABC_Labs.pdf) has some critical data in it, some of which have been redacted correctly, while some were not. Can you find an important key that was not redacted properly?

## Solution

Download the file with the command,

```sh
curl -O https://artifacts.picoctf.net/c/84/Financial_Report_for_ABC_Labs.pdf
```

If you use the `pdftotext` command like so,

```sh
pdftotext Financial_Report_for_ABC_Labs.pdf output.txt
```

This reveals the flag, which is `picoCTF{C4n_Y0u_S33_m3_fully}`.

> NOTE: You can install `pdftotext` on `MacOS` with `brew` like so -> `brew install poppler`

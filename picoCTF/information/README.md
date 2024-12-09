# information

## Description

Files can always be changed in a secret way. Can you find the flag? [cat.jpg](https://mercury.picoctf.net/static/7cf6a33f90deeeac5c73407a1bdc99b6/cat.jpg)

## Solution

If you run the `exiftool` on the file, you get the following output

```sh
➜  information git:(main) ✗ exiftool Cat\ \(1\).jpg 
ExifTool Version Number         : 13.00
File Name                       : Cat (1).jpg
Directory                       : .
File Size                       : 878 kB
File Modification Date/Time     : 2024:12:09 20:29:50+05:00
File Access Date/Time           : 2024:12:09 20:30:07+05:00
File Inode Change Date/Time     : 2024:12:09 20:30:05+05:00
File Permissions                : -rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.02
Resolution Unit                 : None
X Resolution                    : 1
Y Resolution                    : 1
Current IPTC Digest             : 7a78f3d9cfb1ce42ab5a3aa30573d617
Copyright Notice                : PicoCTF
Application Record Version      : 4
XMP Toolkit                     : Image::ExifTool 10.80
License                         : cGljb0NURnt0aGVfbTN0YWRhdGFfMXNfbW9kaWZpZWR9
Rights                          : PicoCTF
Image Width                     : 2560
Image Height                    : 1598
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:2:0 (2 2)
Image Size                      : 2560x1598
Megapixels                      : 4.1
```

I noticed the weird string set to "License". Seemed like base64. We can simply decode and try if it actually is,

```sh
➜  information git:(main) ✗ echo "cGljb0NURnt0aGVfbTN0YWRhdGFfMXNfbW9kaWZpZWR9" | base64 -d
picoCTF{the_m3tadata_1s_modified}
```

So `picoCTF{the_m3tadata_1s_modified}` is the flag.

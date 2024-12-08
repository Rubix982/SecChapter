# CanYouSee

## Description

How about some hide and seek? Download this file [here](https://artifacts.picoctf.net/c_titan/131/unknown.zip).

## Solution

This will download a `zip` file. If we unzip it,

```sh
unzip "PicoCTF Artifacts.zip"
```

We will produce a file called `ukn_reality.jpeg`.

If we run `exiftool` on this file, we get the following output,

```text
➜  CanYouSee git:(main) ✗ exiftool ukn_reality.jpg 
ExifTool Version Number         : 13.00
File Name                       : ukn_reality.jpg
Directory                       : .
File Size                       : 2.3 MB
File Modification Date/Time     : 2024:03:12 05:05:57+05:00
File Access Date/Time           : 2024:12:08 16:38:44+05:00
File Inode Change Date/Time     : 2024:12:08 16:27:34+05:00
File Permissions                : -rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Resolution Unit                 : inches
X Resolution                    : 72
Y Resolution                    : 72
XMP Toolkit                     : Image::ExifTool 11.88
Attribution URL                 : cGljb0NURntNRTc0RDQ3QV9ISUREM05fZDhjMzgxZmR9Cg==
Image Width                     : 4308
Image Height                    : 2875
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:2:0 (2 2)
Image Size                      : 4308x2875
Megapixels                      : 12.4
```

We can see in the "Attribution URL" a base64 string. We can decode it with `base64`.

We get out flag like this,

```sh
➜  CanYouSee git:(main) ✗ echo "cGljb0NURntNRTc0RDQ3QV9ISUREM05fZDhjMzgxZmR9Cg==" | base64 -d
picoCTF{ME74D47A_HIDD3N_d8c381fd}
```

Another way was to call `strings -10` on the file and output the contents. This is command that was run to generate `strings.txt`.

The output can be seen as,

```text
<rdf:RDF xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'>
 <rdf:Description rdf:about=''
  xmlns:cc='http://creativecommons.org/ns#'>
  <cc:attributionURL rdf:resource='cGljb0NURntNRTc0RDQ3QV9ISUREM05fZDhjMzgxZmR9Cg=='/>
 </rdf:Description>
</rdf:RDF>
</x:xmpmeta>
```

Again, we can notice the base64 string in the `attributionURL` header.

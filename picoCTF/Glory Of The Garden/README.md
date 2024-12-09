# Glory Of The Garden

## Description

This [garden](https://jupiter.challenges.picoctf.org/static/43c4743b3946f427e883f6b286f47467/garden.jpg) contains more than it seems.

## Solution

Doing `exiftool` on the file did not help,

```sh
➜  Glory Of The Garden git:(main) ✗ exiftool Garden\ \(1\).jpg 
ExifTool Version Number         : 13.00
File Name                       : Garden (1).jpg
Directory                       : .
File Size                       : 2.3 MB
File Modification Date/Time     : 2024:12:09 20:34:00+05:00
File Access Date/Time           : 2024:12:09 20:34:03+05:00
File Inode Change Date/Time     : 2024:12:09 20:34:18+05:00
File Permissions                : -rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Resolution Unit                 : inches
X Resolution                    : 72
Y Resolution                    : 72
Profile CMM Type                : Linotronic
Profile Version                 : 2.1.0
Profile Class                   : Display Device Profile
Color Space Data                : RGB
Profile Connection Space        : XYZ
Profile Date Time               : 1998:02:09 06:49:00
Profile File Signature          : acsp
Primary Platform                : Microsoft Corporation
CMM Flags                       : Not Embedded, Independent
Device Manufacturer             : Hewlett-Packard
Device Model                    : sRGB
Device Attributes               : Reflective, Glossy, Positive, Color
Rendering Intent                : Perceptual
Connection Space Illuminant     : 0.9642 1 0.82491
Profile Creator                 : Hewlett-Packard
Profile ID                      : 0
Profile Copyright               : Copyright (c) 1998 Hewlett-Packard Company
Profile Description             : sRGB IEC61966-2.1
Media White Point               : 0.95045 1 1.08905
Media Black Point               : 0 0 0
Red Matrix Column               : 0.43607 0.22249 0.01392
Green Matrix Column             : 0.38515 0.71687 0.09708
Blue Matrix Column              : 0.14307 0.06061 0.7141
Device Mfg Desc                 : IEC http://www.iec.ch
Device Model Desc               : IEC 61966-2.1 Default RGB colour space - sRGB
Viewing Cond Desc               : Reference Viewing Condition in IEC61966-2.1
Viewing Cond Illuminant         : 19.6445 20.3718 16.8089
Viewing Cond Surround           : 3.92889 4.07439 3.36179
Viewing Cond Illuminant Type    : D50
Luminance                       : 76.03647 80 87.12462
Measurement Observer            : CIE 1931
Measurement Backing             : 0 0 0
Measurement Geometry            : Unknown
Measurement Flare               : 0.999%
Measurement Illuminant          : D65
Technology                      : Cathode Ray Tube Display
Red Tone Reproduction Curve     : (Binary data 2060 bytes, use -b option to extract)
Green Tone Reproduction Curve   : (Binary data 2060 bytes, use -b option to extract)
Blue Tone Reproduction Curve    : (Binary data 2060 bytes, use -b option to extract)
Image Width                     : 2999
Image Height                    : 2249
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:2:0 (2 2)
Image Size                      : 2999x2249
Megapixels                      : 6.7
```

But we want the flag, it is likely inside the file. It could be just it exists somewhere in the hex values, and not a part of the headers.

JPEG file is an interesting file format. It has flags to mark and stop the declaration of certain headers. More can read from the [Wikipedia Page On Jpeg](https://en.wikipedia.org/wiki/JPEG).

Still, we can try `strings` and check what we can find. We can expect the flag to contain at least 10 characters, we can run the below command and see what we can find,

```sh
➜  Glory Of The Garden git:(main) ✗ strings -10 Garden\ \(1\).jpg 
```

At the very end, we get the below output,

```text
...
...
...
UZzkmu9eQ)=
hIINJ1Q[kgc
}7;=rdk[ub
Z2.]NGpONM:
T}r3]D)gq

BkR>i!>iB=
IpWTKFT$)8
M=u4wi'&Cif
4Cm
   mq+mb:g
=1H"#b0',8
hlk7pi6?iwL
aa,yD=E}..
3`|9pu]F9~C3
6RHK>e\oB:g
v0,'x^D99]
}4s,5'*x,<.
Fquau);^=l|
Pj2Oe2M:DR<
           *
yuk
   "@I=Tc
*}r=sNFK}.e#
mN5'MBNPm?
09>WE:1NMiRz
ZRikwmum#|5iS
Y#B|+4;AlK ]
o<S#yrG dld
pEtN.mm.mle
\GhZY?y'oA
6L4n>R;r}+
wae:uc(>YwG
Here is a flag "picoCTF{more_than_m33ts_the_3y3657BaB2C}"
```

So now, we see that the flag is `picoCTF{more_than_m33ts_the_3y3657BaB2C}`, which is the required flag.
